#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned a, unsigned b, unsigned c)
{
    if (n == 1) {
        answer(0);
    } else {
        const unsigned d = std::min(a, b);
        answer(d + (n - 2) * std::min(c, d));
    }
}

int main()
{
    unsigned n, a, b, c;
    std::cin >> n >> a >> b >> c;

    solve(n, a, b, c);

    return 0;
}

