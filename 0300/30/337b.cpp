#include <iostream>
#include <numeric>

void answer(unsigned x, unsigned y)
{
    std::cout << x << '/' << y << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    if (a * d < b * c) {
        std::swap(a, b);
        std::swap(c, d);
    }

    const unsigned q = a * d, p = q - b * c, g = std::gcd(p, q);

    answer(p / g, q / g);
}

int main()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);

    return 0;
}
