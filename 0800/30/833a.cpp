#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

std::vector<std::pair<integer, unsigned>> c;

void initialize()
{
    for (integer i = 1; i <= 1'000'000; ++i)
        c.emplace_back(i * i * i, i);
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b)
{
    const auto it = std::lower_bound(c.begin(), c.end(), std::make_pair(1ull * a * b, 0u));

    answer(it != c.end() && a % it->second == 0 && b % it->second == 0);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
