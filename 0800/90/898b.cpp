#include <iostream>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    unsigned x = n / a;
    for (unsigned r = n % a; x > 0 && r % b != 0; --x, r += a);

    n -= x * a;

    if (n % b != 0)
        return no_answer();

    answer(x, n / b);
}

int main()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}

