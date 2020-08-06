#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned c = n;
    while (n != 1) {
        unsigned p = 2;
        while (p * p <= n && n % p != 0)
            ++p;

        if (n % p != 0)
            p = n;

        n /= p;
        c += n;
    }

    answer(c);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

