#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned b, unsigned g, unsigned n)
{
    const unsigned bb = std::min(b, n);
    const unsigned gb = std::min(g, n);

    answer(bb - (n - gb) + 1);
}

int main()
{
    unsigned b, g, n;
    std::cin >> b >> g >> n;

    solve(b, g, n);

    return 0;
}

