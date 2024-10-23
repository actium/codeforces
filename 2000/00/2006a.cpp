#include <iostream>
#include <string>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g, const std::string& s)
{
    const size_t n = g.size();

    unsigned f[4] = {};         // 0 : 1 : ? : total ?
    for (size_t i = 1; i < n; ++i) {
        if (g[i].size() == 1)
            ++f[(s[i] != '0') + (s[i] == '?')];
        else
            f[3] += (s[i] == '?');
    }

    if (s[0] == '0')
        return answer(f[1] + (f[2] + 1) / 2);

    if (s[0] == '1')
        return answer(f[0] + (f[2] + 1) / 2);

    if (f[0] != f[1] || f[2] % 2 == 0)
        return answer(std::max(f[0], f[1]) + f[2] / 2);

    answer(f[0] + f[2] / 2 + f[3] % 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
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
