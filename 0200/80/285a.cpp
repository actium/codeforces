#include <iostream>

void solve(unsigned n, unsigned k)
{
    const char* separator = "";
    for (unsigned x = 1; x < n - k; ++x) {
        std::cout << separator << x;
        separator = " ";
    }
    for (unsigned x = 0; x <= k; ++x) {
        std::cout << separator << n - x;
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

