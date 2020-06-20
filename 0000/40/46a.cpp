#include <iostream>

void solve(size_t n)
{
    const char* separator = "";
    for (size_t i = 1, x = 2; i < n; ++i, x += i) {
        for ( ; x > n; x -= n);
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

