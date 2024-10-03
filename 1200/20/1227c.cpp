#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    std::vector<std::pair<size_t, size_t>> p;

    const auto fix = [&](size_t i, char x) {
        if (s[i] == x)
            return;

        size_t j = i + 1;
        while (s[j] != x)
            ++j;

        p.emplace_back(i, j);

        std::reverse(s.begin() + i, s.begin() + j + 1);
    };

    for (size_t i = 0; i + 2 < 2 * k; ++i)
        fix(i, "()"[i%2]);

    for (size_t i = 0; i <= n / 2 - k; ++i)
        fix(2 * k - 2 + i, '(');

    answer(p);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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
