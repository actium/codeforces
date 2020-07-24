#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer m, unsigned a, unsigned b)
{
    const integer r = n % m;

    const integer c1 = (m - r) * a;
    const integer c2 = r * b;
    const integer c = std::min(c1, c2);

    answer(c);
}

int main()
{
    integer n, m;
    std::cin >> n >> m;

    unsigned a, b;
    std::cin >> a >> b;

    solve(n, m, a, b);

    return 0;
}

