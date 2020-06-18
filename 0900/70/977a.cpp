#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    while (k-- > 0) {
        if (n % 10 == 0)
            n /= 10;
        else
            --n;
    }

    answer(n);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

