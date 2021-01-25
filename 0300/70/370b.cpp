#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::set<unsigned>>& c)
{
    const size_t n = c.size();

    const auto check = [&](size_t i) {
        for (size_t j = 0; j < n; ++j) {
            if (j != i && std::all_of(c[j].cbegin(), c[j].cend(), [&](unsigned q) { return c[i].count(q) == 1; }))
                return false;
        }
        return true;
    };

    for (size_t i = 0; i < n; ++i)
        answer(check(i));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::set<unsigned>> c(n);
    for (size_t i = 0; i < n; ++i) {
        size_t m;
        std::cin >> m;

        for (size_t j = 0; j < m; ++j) {
            unsigned a;
            std::cin >> a;

            c[i].insert(a);
        }
    }

    solve(c);

    return 0;
}

