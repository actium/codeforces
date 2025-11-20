#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string compare(const std::string& x, const std::string& y)
{
    const size_t n = x.size();

    std::string t = "0A0B";

    unsigned f[10] = {}, g[10] = {};
    for (size_t i = 0; i < n; ++i) {
        t[0] += (x[i] == y[i]);
        t[2] -= (x[i] == y[i]);

        ++f[x[i]-'0'];
        ++g[y[i]-'0'];
    }

    for (size_t i = 0; i < 10; ++i)
        t[2] += std::min(f[i], g[i]);

    return t;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& n, unsigned j, unsigned k)
{
    std::vector<std::string> p;
    do {
        p.push_back(n);
    } while (std::next_permutation(n.begin(), n.end()));

    answer(compare(p[j-1], p[k-1]));
}

void test_case()
{
    std::string n;
    std::cin >> n;

    unsigned j, k;
    std::cin >> j >> k;

    solve(n, j, k);
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
