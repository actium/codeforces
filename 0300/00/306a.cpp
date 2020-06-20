#include <iostream>

void solve(size_t n, size_t m)
{
    const char* separator = "";
    for (size_t i = 0; i < m; ++i) {
        const size_t k = n / (m - i);
        std::cout << separator << k;
        n -= k;
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

