#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    const unsigned t = (c * a + b - 1) / b;
    answer((t * (a - b) + a - 1) / a);
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

