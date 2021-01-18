#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned k = 0;
    for (unsigned a = 1; a <= n; ++a) {
        for (unsigned b = 1; b <= n; ++b) {
            const unsigned c = a ^ b;
            if (c <= n && a + b > c && a + c > b && b + c > a)
                ++k;
        }
    }

    answer(k / 6);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

