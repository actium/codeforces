#include <iostream>

using integer = long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer a, integer b, integer r)
{
    if (a > b)
        std::swap(a, b);

    integer x = 0, m = 1LL << 60;
    while (m != 0 && (a & m) == (b & m))
        m >>= 1;

    while (m != 0) {
        m >>= 1;

        if ((a & m) == 0 && (b & m) != 0 && (x | m) <= r)
            x |= m;
    }

    answer(std::abs((a ^ x) - (b ^ x)));
}

void test_case()
{
    integer a, b, r;
    std::cin >> a >> b >> r;

    solve(a, b, r);
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
