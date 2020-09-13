#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer a, integer b)
{
    if (a < b)
        std::swap(a, b);

    integer k = 0;
    while (b != 0) {
        k += a / b;
        a %= b;
        std::swap(a, b);
    }

    answer(k);
}

int main()
{
    integer a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

