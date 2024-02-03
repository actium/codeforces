#include <iostream>

void solve(unsigned n)
{
    if (n < 4) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';

    switch (n) {
        case 4:
            std::cout << "4 * 3 = 12" << '\n';
            std::cout << "12 * 2 = 24" << '\n';
            std::cout << "24 * 1 = 24" << '\n';
            break;

        case 5:
            std::cout << "5 * 4 = 20" << '\n';
            std::cout << "20 + 3 = 23" << '\n';
            std::cout << "23 + 2 = 25" << '\n';
            std::cout << "25 - 1 = 24" << '\n';
            break;

        default:
            std::cout << "6 * 4 = 24" << '\n';

            std::cout << "3 - 2 = 1" << '\n';
            std::cout << "1 - 1 = 0" << '\n';

            std::cout << "5 * 0 = 0" << '\n';
            for (unsigned i = 7; i <= n; ++i)
                std::cout << i << " * 0 = 0" << '\n';

            std::cout << "24 + 0 = 24" << '\n';
            break;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
