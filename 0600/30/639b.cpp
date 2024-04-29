#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned d, unsigned h)
{
    if (n == 2)
        return answer({ std::make_pair(1, 2) });

    if (d == 1 || d > 2 * h)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> e;
    {
        unsigned x = 2;
        for (unsigned i = 0, p = 1; i < h; ++i) {
            e.emplace_back(p, x);
            p = x++;
        }
        for (unsigned i = 0, p = 1; i < d - h; ++i) {
            e.emplace_back(p, x);
            p = x++;
        }
        while (x <= n) {
            e.emplace_back(1 + (d == h), x);
            ++x;
        }
    }

    answer(e);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, d, h;
    std::cin >> n >> d >> h;

    solve(n, d, h);

    return 0;
}
