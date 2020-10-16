#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m, unsigned a, unsigned b)
{
    if (m * a < b)
        return answer(n * a);

    const unsigned c1 = n / m * b + n % m * a;
    const unsigned c2 = n / m * b + b;

    answer(std::min(c1, c2));
}

int main()
{
    unsigned n, m, a, b;
    std::cin >> n >> m >> a >> b;

    solve(n, m, a, b);

    return 0;
}

