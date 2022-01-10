#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    unsigned k = 0;
    while (n != m) {
        while (n < m && m % 2 == 0) {
            m /= 2;
            ++k;
        }

        if (m != n) {
            ++m;
            ++k;
        }
    }

    answer(k);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
