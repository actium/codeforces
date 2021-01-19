#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<size_t, size_t>> x;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            x.emplace_back(i, j);
    }

    const auto compare = [&](const std::pair<size_t, size_t>& x, const std::pair<size_t, size_t>& y) {
        return a[x.first][x.second] < a[y.first][y.second];
    };
    std::sort(x.begin(), x.end(), compare);

    std::vector<unsigned> p(n);
    for (size_t k = 0; k < n; ) {
        const auto [i, j] = x.back();
        x.pop_back();

        if (p[i] == 0 && p[j] == 0) {
            p[i] = 1 + j;
            p[j] = 1 + i;
            k += 2;
        }
    }

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;
    n *= 2;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            std::cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    solve(a);

    return 0;
}

