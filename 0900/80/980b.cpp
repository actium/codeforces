#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    std::vector<std::string> g(4, std::string(n, '.'));
    if (k % 2 == 1) {
        g[1][n/2] = '#';
        --k;
    }
    for (size_t i = 1; i < 3; ++i) {
        for (size_t u = 1, v = n-2; u < v && k != 0; ++u, --v, k -= 2) {
            g[i][u] = '#';
            g[i][v] = '#';
        }
    }
    for (size_t i = 2; k != 0; --i, --k)
        g[i][n/2] = '#';

    answer(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
