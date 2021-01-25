#include <iostream>
#include <set>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "FAIL", "WIN" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::set<size_t>>& f)
{
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = i + 1; j < 4; ++j) {
            for (size_t k = j + 1; k < 5; ++k) {
                if (f[i].count(j) == f[i].count(k) && f[i].count(j) == f[j].count(k))
                    return answer(true);
            }
        }
    }

    answer(false);
}

int main()
{
    size_t m;
    std::cin >> m;

    std::vector<std::set<size_t>> f(5);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b;
        --a, --b;

        f[a].insert(b);
        f[b].insert(a);
    }

    solve(f);

    return 0;
}

