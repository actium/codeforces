#include <iostream>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer m)
{
    const auto count = [m](integer x) {
        integer q = 0;
        for (integer k = 2; k * k * k <= x; ++k) {
            const integer c = k * k * k;
            q += x / c;
        }
        return q;
    };

    integer lb = 0, ub = oo;
    while (ub - lb > 1) {
        const integer mid = (lb + ub) / 2;
        (count(mid) < m ? lb : ub) = mid;
    }

    count(ub) == m ? answer(ub) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer m;
    std::cin >> m;

    solve(m);

    return 0;
}
