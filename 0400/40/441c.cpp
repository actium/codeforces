#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<std::pair<unsigned, unsigned>>>& v)
{
    for (const std::vector<std::pair<unsigned, unsigned>>& x : v) {
        std::cout << x.size();
        for (const std::pair<unsigned, unsigned>& p : x)
            std::cout << ' ' << p.first << ' ' << p.second;
        std::cout << '\n';
    }
}

void solve(unsigned n, unsigned m, unsigned k)
{
    std::vector<std::pair<unsigned, unsigned>> p;
    for (unsigned r = 1; r <= n; ++r) {
        if (r % 2 == 1) {
            for (unsigned c = 1; c <= m; ++c)
                p.emplace_back(r, c);
        } else {
            for (unsigned c = m; c >= 1; --c)
                p.emplace_back(r, c);
        }
    }

    std::vector<std::vector<std::pair<unsigned, unsigned>>> v(k);
    for (unsigned i = 1; i < k; ++i) {
        v[i].push_back(p.back());
        p.pop_back();
        v[i].push_back(p.back());
        p.pop_back();
    }
    v[0] = std::move(p);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);

    return 0;
}
