#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    unsigned v = 1;
    for (unsigned long long b = 3; n != 0; n /= 2) {
        if (n % 2 == 1)
            v = v * b % m;

        b = b * b % m;
    }

    answer((v + m - 1) % m);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
