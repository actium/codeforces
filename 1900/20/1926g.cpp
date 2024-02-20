#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

std::pair<unsigned, unsigned> solve(const std::vector<std::vector<size_t>>& g, size_t u, const std::string& s)
{
    std::pair<unsigned, unsigned> v = { 0, 0 };
    for (const size_t x : g[u]) {
        const std::pair<unsigned, unsigned> y = solve(g, x, s);
        v.first += std::min(y.first, y.second + 1);
        v.second += std::min(y.first + 1, y.second);
    }

    if (s[u] == 'S')
        v.first = oo;
    if (s[u] == 'P')
        v.second = oo;

    return v;
}

void solve(const std::vector<std::vector<size_t>>& g, const std::string& s)
{
    const std::pair<unsigned, unsigned> v = solve(g, 0, s);
    answer(std::min(v.first, v.second));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned x;
        std::cin >> x;

        g[x-1].push_back(i);
    }

    std::string s;
    std::cin >> s;

    solve(g, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
