#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    unsigned c = 0, d = 0;
    while (a != 0) {
        c += a;
        d += a;
        a = d / b;
        d %= b;
    }

    answer(c);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

