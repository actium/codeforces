#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    constexpr unsigned c[10] = { 2, 7, 2, 3, 3, 4, 2, 5, 1, 2 };

    answer(c[n/10] * c[n%10]);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

