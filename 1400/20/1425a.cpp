#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    integer k[2] = {};
    for (size_t i = 0; n != 0; i ^= 1) {
        if (n % 2 == 1 || (n % 4 == 0 && n != 4)) {
            --n;
            ++k[i];
        } else {
            n /= 2;
            k[i] += n;
        }
    }

    answer(k[0]);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
