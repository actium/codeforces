#include <iostream>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& row : v) {
        const char* separator = "";
        for (const unsigned x : row) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(unsigned n, unsigned a, unsigned b)
{
    if (a * b < n)
        return no_answer();

    std::vector<std::vector<unsigned>> g(a, std::vector<unsigned>(b));
    for (unsigned i = 0, k = 1; i < a; ++i) {
        for (unsigned j = 0; j < b && k <= n; ++j, ++k) {
            if (i % 2 == 0 || b % 2 == 1) {
                g[i][j] = k;
            } else {
                g[i][b-1-j] = k;
            }
        }
    }

    answer(g);
}

int main()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}

