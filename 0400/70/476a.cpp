#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (n < m)
        return answer(-1);

    const unsigned k = n / 2 + n % 2;
    answer(k + (m - k % m) % m);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

