#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    unsigned c = 0, d = 0;
    do {
        if (n % 10 == 0)
            --k;
        else
            ++c;

        ++d, n /= 10;
    } while (n != 0 && k != 0);

    answer(k == 0 ? c : d - 1);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

