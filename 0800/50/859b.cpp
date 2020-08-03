#include <iostream>

#include <cmath>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    const unsigned w = sqrt(n);
    const unsigned h = (n + w - 1) / w;

    answer(2 * (w + h));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

