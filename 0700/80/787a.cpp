#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    for (unsigned i = 0; i < 100 * 100; ++i) {
        if (b == d)
            return answer(b);

        if (b < d)
            b += a;
        else
            d += c;
    }

    no_answer();
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    unsigned c, d;
    std::cin >> c >> d;

    solve(a, b, c, d);

    return 0;
}

