#include <algorithm>
#include <iostream>
#include <vector>

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    std::vector<unsigned> d(n);
    for (const auto& r : g) {
        for (const size_t x : r)
            ++d[x];
    }

    std::vector<size_t> s;
    for (size_t i = 0; i < n; ++i) {
        if (d[i] == 0)
            s.push_back(i);
    }
    for (size_t i = 0; i < s.size(); ++i) {
        const unsigned x = s[i];
        for (const unsigned y : g[x]) {
            if (--d[y] == 0)
                s.push_back(y);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            const auto& r = g[s[j]];
            if (std::find(r.cbegin(), r.cend(), s[i]) == r.cend())
                return answer(s[i], s[j]);
        }
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    const size_t k = n * (n - 1) / 2;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < k; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        g[y-1].push_back(x-1);
    }

    solve(g);

    return 0;
}

