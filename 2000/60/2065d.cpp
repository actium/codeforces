#include <algorithm>
#include <iostream>
#include <numeric>
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

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    std::vector<integer> r(n);
    for (size_t i = 0; i < n; ++i)
        r[i] = std::accumulate(a[i].begin(), a[i].end(), 0ull);

    std::vector<size_t> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return r[i] > r[j]; });

    integer s = 0, t = 0;
    for (const size_t i : p) {
        std::for_each(a[i].begin(), a[i].end(), [&](unsigned v) {
            t += v;
            s += t;
        });
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);
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
