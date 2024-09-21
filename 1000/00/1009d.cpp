#include <iostream>
#include <numeric>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "Possible" << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (m + 1 < n)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> e;
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = i + 1; j <= n && e.size() < m; ++j) {
            if (std::gcd(i, j) == 1)
                e.emplace_back(i, j);
        }
    }

    e.size() == m ? answer(e) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
