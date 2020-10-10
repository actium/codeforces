#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned k = 0;
    while (n != 0) {
        unsigned d = 0;
        for (unsigned x = n; x != 0; x /= 10)
            d = std::max(d, x % 10);

        n -= d;
        ++k;
    }

    answer(k);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

