#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& a : v) {
        const char* separator = "";
        for (const unsigned x : a) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, size_t k)
{
    if (k > n * n)
        return no_answer();

    std::vector<std::vector<unsigned>> x(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n && k > 0; ++i) {
        x[i][i] = 1; --k;

        for (size_t j = i+1; j < n && k > 1; ++j) {
            x[i][j] = 1; --k;
            x[j][i] = 1; --k;
        }
    }

    answer(x);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
