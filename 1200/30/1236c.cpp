#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const auto& r : v) {
        const char* separator = "";
        for (const unsigned x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(unsigned n)
{
    std::vector<std::vector<unsigned>> x(n, std::vector<unsigned>(n));
    for (size_t j = 0; j < n; j += 2) {
        for (size_t i = 0; i < n; ++i)
            x[i][j] = 1 + j * n + i;
    }
    for (size_t j = 1; j < n; j += 2) {
        for (size_t i = 0; i < n; ++i)
            x[i][j] = n + j * n - i;
    }

    answer(x);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

