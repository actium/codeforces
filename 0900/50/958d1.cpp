#include <array>
#include <iostream>
#include <map>
#include <numeric>
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

void solve(const std::vector<std::array<unsigned, 3>>& c)
{
    const size_t m = c.size();

    const auto v = [](const std::array<unsigned, 3>& x) {
        const unsigned d = std::gcd(x[0] + x[1], x[2]);
        return std::make_pair<unsigned, unsigned>((x[0] + x[1]) / d, x[2] / d);
    };

    std::map<std::pair<unsigned, unsigned>, unsigned> f;
    for (const auto& x : c)
        ++f[v(x)];

    std::vector<unsigned> q(m);
    for (size_t i = 0; i < m; ++i)
        q[i] = f[v(c[i])];

    answer(q);
}

int main()
{
    unsigned m;
    scanf("%u\n", &m);

    std::vector<std::array<unsigned, 3>> c(m);
    for (unsigned i = 0; i < m; ++i)
        scanf("(%u+%u)/%u\n", &c[i][0], &c[i][1], &c[i][2]);

    solve(c);

    return 0;
}
