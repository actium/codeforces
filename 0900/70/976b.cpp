#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned m, unsigned long long k)
{
    if (k < n)
        return answer(1 + k, 1);

    const unsigned r = n - (k - n) / (m - 1);
    const unsigned q = (k - n) % (m - 1);
    const unsigned c = (r % 2 == 0 ? 2 + q : m - q);

    answer(r, c);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    unsigned long long k;
    std::cin >> k;

    solve(n, m, k);

    return 0;
}

