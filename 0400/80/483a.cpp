#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer x, integer y, integer z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer l, integer r)
{
    for (integer a = l; a < r-1; ++a) {
        for (integer b = a + 1; b < r; ++b) {
            if (std::gcd(a, b) != 1)
                continue;

            for (integer c = b + 1; c <= r; ++c) {
                if (std::gcd(b, c) != 1)
                    continue;

                if (std::gcd(a, c) != 1)
                    return answer(a, b, c);
            }
        }
    }

    no_answer();
}

int main()
{
    integer l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}

