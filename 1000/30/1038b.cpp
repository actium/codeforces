#include <iostream>

void solve(unsigned n)
{
    if (n < 3) {
        std::cout << "No" << '\n';
    } else {
        const unsigned x = (n + 1) / 2;

        std::cout << "Yes" << '\n';
        std::cout << 1 << ' ' << x << '\n';
        std::cout << n-1;
        for (unsigned i = 1; i <= n; ++i) {
            if (i != x)
                std::cout << ' ' << i;
        }
        std::cout << '\n';
    }
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

