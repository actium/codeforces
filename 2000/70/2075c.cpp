#include <algorithm>
#include <iostream>
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

void solve(unsigned n, std::vector<unsigned>& a)
{
    std::sort(a.begin(), a.end());

    integer c = 0;
    for (unsigned k = 1; k < n; ++k) {
        const auto u = a.end() - std::lower_bound(a.begin(), a.end(), k);
        const auto v = a.end() - std::lower_bound(a.begin(), a.end(), n - k);
        c += (std::max(u, v) - 1ull) * std::min(u, v);
    }

    answer(c);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);
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
