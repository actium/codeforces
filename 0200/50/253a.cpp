#include <iostream>
#include <string>

#include <cstdio>

void solve(size_t n, size_t m)
{
    if (n > m) {
        while (m > 0) {
            std::cout << "BG";
            --n, --m;
        }
        std::cout << std::string(n, 'B') << '\n';
    } else {
        while (n > 0) {
            std::cout << "GB";
            --n, --m;
        }
        std::cout << std::string(m, 'G') << '\n';
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

