#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned s)
{
    answer((s + n - 1) / n);
}

int main()
{
    unsigned n, s;
    std::cin >> n >> s;

    solve(n, s);

    return 0;
}

