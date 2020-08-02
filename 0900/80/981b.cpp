#include <iostream>
#include <map>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::map<unsigned, unsigned>& c1, const std::map<unsigned, unsigned>& c2)
{
    unsigned long long s = 0;
    for (const auto& e : c1) {
        const auto it = c2.find(e.first);
        if (it == c2.cend())
            s += e.second;
        else
            s += std::max(e.second, it->second);
    }
    for (const auto& e : c2) {
        if (c1.count(e.first) == 0)
            s += e.second;
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::map<unsigned, unsigned> c1;
    for (size_t i = 0; i < n; ++i) {
        unsigned a, x;
        std::cin >> a >> x;

        c1.emplace(a, x);
    }

    size_t m;
    std::cin >> m;

    std::map<unsigned, unsigned> c2;
    for (size_t i = 0; i < m; ++i) {
        unsigned b, y;
        std::cin >> b >> y;

        c2.emplace(b, y);
    }

    solve(c1, c2);

    return 0;
}

