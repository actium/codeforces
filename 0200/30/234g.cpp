#include <iostream>
#include <vector>

using team_t = std::vector<unsigned>;

void answer(const std::vector<team_t>& v)
{
    std::cout << v.size() << '\n';

    for (const team_t& x : v) {
        std::cout << x.size();

        for (const unsigned u : x)
            std::cout << ' ' << u;

        std::cout << '\n';
    }
}

void plan(const team_t& t, std::vector<team_t>& q, size_t d)
{
    const size_t k = t.size();
    if (k == 1)
        return;

    if (d == q.size())
        q.emplace_back();

    std::pair<team_t, team_t> s;
    for (size_t i = 0; i < k; ++i) {
        if (i % 2 == 0) {
            s.first.push_back(t[i]);
            q[d].push_back(t[i]);
        } else {
            s.second.push_back(t[i]);
        }
    }

    plan(s.first, q, d+1);
    plan(s.second, q, d+1);
}

void solve(unsigned n)
{
    team_t t(n);
    for (size_t i = 0; i < n; ++i)
        t[i] = i + 1;

    std::vector<team_t> q;
    plan(t, q, 0);

    answer(q);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
