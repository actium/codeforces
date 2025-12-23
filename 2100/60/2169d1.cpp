#include <iostream>

using integer = unsigned long long;

constexpr integer ub = 1000000000000;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer k, integer y, unsigned x)
{
    if (y == 1)
        return no_answer();

    while (k <= ub && x-- != 0) {
        integer c = k / y, r = k % y;
        while (c != 0 && k <= ub) {
            k += c;
            r += c;
            c = r / y;
            r = r % y;
        }
    }

    if (k <= ub)
        return answer(k);

    no_answer();
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    integer y, k;
    std::cin >> y >> k;

    solve(k, y, x);
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
