#include <iostream>

void solve(unsigned a, unsigned b)
{
    const unsigned n = a + b + 1;

    const char* separator = "";
    for (unsigned i = 0; i < a; ++i) {
        std::cout << separator << n - a + i;
        separator = " ";
    }
    std::cout << separator << n;
    for (unsigned i = 0; i < b; ++i)
        std::cout << ' ' << n - a - i - 1;

    std::cout << '\n';
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

