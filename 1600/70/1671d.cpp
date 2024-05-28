#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

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

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    integer s = 0;
    for (size_t i = 1; i < n; ++i)
        s += (a[i] < a[i-1] ? a[i-1] - a[i] : a[i] - a[i-1]);

    integer v = oo;

    const auto check = [&](unsigned d, unsigned e) {
        v = std::min(v, s + d + e);
    };

    const auto r = std::minmax_element(a.begin(), a.end());

    check(*r.first > 1 ? a[0] - 1 : 0, *r.second < x ? x - a[n-1] : 0);
    check(*r.first > 1 ? a[n-1] - 1 : 0, *r.second < x ? x - a[0] : 0);
    check(*r.first > 1 ? a[0] - 1 : 0, 2 * (x - *r.second));
    check(*r.first > 1 ? a[n-1] - 1 : 0, 2 * (x - *r.second));
    check(2 * (*r.first - 1), *r.second < x ? x - a[n-1] : 0);
    check(2 * (*r.first - 1), *r.second < x ? x - a[0] : 0);
    check(2 * (*r.first - 1), 2 * (x - *r.second));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
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
