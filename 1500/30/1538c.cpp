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

void solve(std::vector<unsigned>& a, unsigned l, unsigned r)
{
    std::sort(a.begin(), a.end());

    integer k = 0;
    for (auto it = a.cbegin(); it != a.cend() && *it <= r; ++it) {
        auto lb = std::next(it);
        if (*it <= l)
            lb = std::lower_bound(lb, a.cend(), l - *it);

        auto ub = std::next(it);
        if (*it <= r)
            ub = std::upper_bound(ub, a.cend(), r - *it);

        k += ub - lb;
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
