#include <iostream>

using integer = unsigned long long;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(integer a, integer b)
{
    unsigned k = 1;
    for (integer x = b; x > a && k != 0; --x)
        k = (k * x) % 10;

    answer(k);
}

int main()
{
    integer a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

