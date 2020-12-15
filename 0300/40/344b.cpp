#include <iostream>

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    if (a + b < c || a + c < b || b + c < a || (a + b - c) % 2 != 0)
        return no_answer();

    const unsigned d = (a + b - c) / 2;
    answer(d, b - d, a - d);
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

