#include <iostream>
#include <vector>

void solve(const std::vector<std::vector<unsigned>>& x)
{
    const size_t n = x.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (x[i][j] == 1)
                std::cout << 1 + j << ' ';
        }
        std::cout << '\n';
    }
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> x(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            std::cin >> x[i][j];
    }

    solve(x);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
