#include <iostream>

using integer = unsigned long long;

constexpr integer oo = 1LL << 60;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

unsigned select_bit(integer x, unsigned p)
{
    return (x >> p) & 0x1;
}

void solve(integer s, integer m)
{
    const auto check = [&](integer q) {
        integer c = 0;
        for (unsigned i = 0; i < 60; ++i) {
            c += q * select_bit(m, i);

            const unsigned d = select_bit(s, i);
            if (c < d)
                return false;

            c -= d;
            c /= 2;
        }
        return true;
    };

    integer lb = 0, ub = oo;
    while (ub - lb > 1) {
        const integer mid = lb + (ub - lb) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    ub != oo ? answer(ub) : no_answer();
}

void test_case()
{
    integer s, m;
    std::cin >> s >> m;

    solve(s, m);
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
