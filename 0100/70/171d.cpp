#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(n == 5 ? 1 : 1 + n % 3);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
