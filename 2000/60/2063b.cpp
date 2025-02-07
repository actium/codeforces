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

integer check(std::vector<unsigned> a, size_t b, size_t e, size_t k)
{
    std::sort(a.begin() + b, a.begin() + e);

    integer s = 0;
    for (size_t i = 0; i < k; ++i)
        s += a[b+i];

    return s;
}

void solve(const std::vector<unsigned>& a, unsigned l, unsigned r)
{
    const size_t n = a.size(), k = r - l + 1;

    const integer p = check(a, 0, r, k), s = check(a, l-1, n, k);
    answer(std::min(p, s));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned l, r;
    std::cin >> l >> r;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, l, r);
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
