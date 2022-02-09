#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    integer k = 1;
    for (unsigned i = 0; i < 5; ++i)
        k *= n - i;

    answer(k / 120 * k);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
