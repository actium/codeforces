#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

integer compute(unsigned ub, integer b, unsigned r)
{
    integer s = 0;
    while (ub >= r) {
        if (ub % 2 == 1)
            s += b;

        ub /= 2;
        b *= 2;
    }
    return s;
}

void solve(unsigned n, unsigned k)
{
    if (n % 2 == 1) {
        answer(compute(n, 1 + n / 2, k));
    } else {
        answer(compute(n / 2, n + 1, k));
    }
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
