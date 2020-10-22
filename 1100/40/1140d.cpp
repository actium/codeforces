#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned s = 0;
    for (unsigned x = 2; x < n; ++x)
        s += x * (x + 1);

    answer(s);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

