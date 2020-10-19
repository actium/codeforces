#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    for (const auto& x : g) {
        if (x.empty())
            continue;

        unsigned k = 0;
        for (const size_t c : x)
            k += g[c].empty();

        if (k < 3)
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned p;
        std::cin >> p;

        g[p-1].push_back(i);
    }

    solve(g);

    return 0;
}

