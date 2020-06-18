#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    const size_t c100 = n / 100;
    n -= c100 * 100;

    const size_t c20 = n / 20;
    n -= c20 * 20;

    const size_t c10 = n / 10;
    n -= c10 * 10;

    const size_t c5 = n / 5;
    n -= c5 * 5;

    answer(c100 + c20 + c10 + c5 + n);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

