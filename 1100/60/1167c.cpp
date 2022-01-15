#include <iostream>
#include <utility>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, const std::vector<std::vector<unsigned>>& g)
{
    std::vector<size_t> r(n), s(n, 1);
    for (size_t i = 0; i < n; ++i)
        r[i] = i;

    const auto root = [&](size_t x) {
        size_t rx = x;
        while (rx != r[rx])
            rx = r[rx];

        while (r[x] != rx)
            x = std::exchange(r[x], rx);

        return rx;
    };

    const auto merge = [&](size_t x, size_t y) {
        size_t rx = root(x), ry = root(y);
        if (rx == ry)
            return;

        if (s[rx] < s[ry])
            std::swap(rx, ry);

        r[ry] = rx;
        s[rx] += s[ry];
    };

    for (const auto& v : g) {
        for (size_t i = 1; i < v.size(); ++i)
            merge(v[i]-1, v[0]-1);
    }

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = s[root(i)];

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> g(m);
    for (auto& v : g) {
        size_t k;
        std::cin >> k;

        v.resize(k);
        for (auto& x : v)
            std::cin >> x;
    }

    solve(n, g);

    return 0;
}
