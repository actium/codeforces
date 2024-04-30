#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using integer = long long;

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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return a[i] < a[j];
    });

    integer s = 0, t = 0;
    {
        std::priority_queue<std::pair<int, unsigned>> q;
        for (const size_t x : p) {
            if (a[x] <= b[x]) {
                s -= a[x];

                q.emplace(-b[x], a[x]);
                if (q.size() > k) {
                    s -= q.top().first;
                    q.pop();
                }

                t = std::max(t, s);
            }
        }
    }

    answer(t);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
