#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned r = 1;
    for (unsigned x = 8; n > 0; n /= 2) {
        if (n & 1) {
            r *= x;
            r %= 10;
        }

        x *= x;
        x %= 10;
    }

    answer(r);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

