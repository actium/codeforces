#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& t)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return a[i] < a[j]; });

    integer v = 0;
    {
        unsigned b = 0;
        std::priority_queue<unsigned> q;
        integer d = 0;

        const auto advance = [&](unsigned x) {
            while (!q.empty() && b < x) {
                d -= q.top();
                q.pop();
                v += d;
                ++b;
            }
        };

        for (size_t i = 0; i < n; ) {
            advance(a[p[i]]);

            if (q.empty())
                b = a[p[i]];

            while (i < n && a[p[i]] == b) {
                q.push(t[p[i]]);
                d += t[p[i]];
                ++i;
            }
        }

        advance(~0u);
    }
    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), t(n);
    std::cin >> a >> t;

    solve(a, t);

    return 0;
}
