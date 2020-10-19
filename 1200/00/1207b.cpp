#include <iostream>
#include <set>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::set<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(size_t n, size_t m, std::vector<std::vector<unsigned>>& a)
{
    std::set<std::pair<size_t, size_t>> p;
    const auto change = [&](size_t i, size_t j) {
        if (a[i][j] != 0 && a[i][j+1] != 0 && a[i+1][j] != 0 && a[i+1][j+1] != 0) {
            a[i][j] = a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 2;
            p.emplace(i, j);
            return true;
        }
        return false;
    };

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            change(i, j);
            change(i, j+1);
            change(i+1, j);
            change(i+1, j+1);
        }
    }

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            if (a[i][j] == 1)
                return no_answer();
        }
    }

    answer(p);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(1+n+1, std::vector<unsigned>(1+m+1));
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j)
            std::cin >> a[i][j];
    }

    solve(n, m, a);

    return 0;
}

