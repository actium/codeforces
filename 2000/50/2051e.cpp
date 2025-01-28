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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return a[i] < a[j];
    });

    std::vector<unsigned> s;
    for (size_t i = 0; i < n; ++i) {
        s.push_back(a[i]);
        s.push_back(b[i]);
    }

    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());

    integer v = 0;
    {
        std::priority_queue<unsigned, std::vector<unsigned>, std::greater<unsigned>> q;

        size_t i = 0;
        for (const unsigned x : s) {
            while (i < n && a[p[i]] < x)
                q.push(b[p[i++]]);

            while (!q.empty() && q.top() < x)
                q.pop();

            if (q.size() <= k)
                v = std::max(v, 1ull * x * (n - i + q.size()));
        }
    }
    answer(v);
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
