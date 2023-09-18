#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, size_t m, const std::string& lb, const std::string& ub)
{
    const size_t n = s.length();

    for (size_t i = 0, j = 0; i < m; ++i) {
        unsigned k = 0, q = ub[i] - lb[i] + 1;
        for (bool p[10] = {}; j < n && k < q; ++j) {
            if (s[j] < lb[i] || s[j] > ub[i])
                continue;

            const unsigned d = s[j] - '0';
            if (!p[d]) {
                p[d] = true;
                ++k;
            }
        }

        if (j == n && k != q)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    size_t m;
    std::cin >> m;

    std::string lb, ub;
    std::cin >> lb >> ub;

    solve(s, m, lb, ub);
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
