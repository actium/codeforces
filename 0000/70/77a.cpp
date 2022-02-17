#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::pair<std::string, std::string>>& l, unsigned a, unsigned b, unsigned c)
{
    const std::string h[7] = { "Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal" };

    constexpr std::pair<unsigned, unsigned> oo = { ~0u, 0 };

    const auto evaluate = [&](unsigned x) -> std::pair<unsigned, unsigned> {
        std::vector<size_t> p[3];
        for (size_t i = 0; i < 7; ++i) {
            p[x % 3].push_back(i);
            x /= 3;
        }

        if (p[0].empty() || p[1].empty() || p[2].empty())
            return oo;

        unsigned q = 0;
        for (size_t i = 0; i < 3; ++i) {
            for (const size_t j : p[i]) {
                for (const size_t k : p[i])
                    q += std::count(l.cbegin(), l.cend(), std::make_pair(h[j], h[k]));
            }
        }

        const auto r = std::minmax({ a / p[0].size(), b / p[1].size(), c / p[2].size() });

        return { r.second - r.first, q };
    };

    unsigned d = ~0u, k = 0;
    for (unsigned i = 0; i < 2187; ++i) {
        const std::pair<unsigned, unsigned> v = evaluate(i);
        if (v.first < d || (v.first == d && v.second > k))
            d = v.first, k = v.second;
    }

    answer(d, k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string>> l(n);
    for (size_t i = 0; i < n; ++i) {
        std::string x;
        std::cin >> l[i].first >> x >> l[i].second;
    }

    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(l, a, b, c);

    return 0;
}
