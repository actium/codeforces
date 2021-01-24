#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    const auto check = [b](unsigned c) {
        unsigned x = b;
        for ( ; c != 0; c /= 10) {
            if (c % 10 != 4 && c % 10 != 7)
                continue;

            if (c % 10 != x % 10)
                return false;

            x /= 10;
        }
        return x == 0;
    };

    while (!check(++a));

    answer(a);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

