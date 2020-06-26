#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(unsigned a, unsigned x, unsigned n)
{
    std::cout << a << x;
    while (--n > 0)
        std::cout << '0';

    std::cout << '\n';
}

void solve(unsigned a, unsigned b, unsigned n)
{
    for (size_t i = 0; i < 10; ++i) {
        if ((a * 10 + i) % b == 0)
            return answer(a, i, n);
    }

    answer(-1);
}

int main()
{
    unsigned a, b, n;
    std::cin >> a >> b >> n;

    solve(a, b, n);

    return 0;
}

