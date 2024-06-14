#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << v.size() << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(unsigned k)
{
    std::vector<std::string> g(1, "0");
    for (unsigned c = 0, x = 0; c != k; ) {
        const unsigned n = g.size(), d = (n - x) * (n - x - 1) / 2;
        if (c + d > k) {
            ++x;
        } else {
            g.emplace_back(n + 1, '0');

            for (size_t i = 0; i < x; ++i)
                g[i].push_back('0');

            for (size_t i = x; i < n; ++i) {
                g[i].push_back('1');
                g[n][i] = '1';
            }

            c += d;
        }
    }

    answer(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}
