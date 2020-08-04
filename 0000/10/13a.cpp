#include <iostream>
#include <numeric>

unsigned sum(unsigned a, unsigned b)
{
    unsigned s = 0;
    while (a != 0) {
        s += a % b;
        a /= b;
    }
    return s;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << '/' << y << '\n';
}

void solve(unsigned a)
{
    unsigned s = 0;
    for (unsigned b = 2; b < a; ++b)
        s += sum(a, b);

    const unsigned d = std::gcd(s, a-2);
    answer(s / d, (a-2) / d);
}

int main()
{
    unsigned a;
    std::cin >> a;

    solve(a);

    return 0;
}

