#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

size_t index(char c1, char c2, unsigned k)
{
    return ((c1 - 'a') * 26 + c2 - 'a') * 26 + k;
}

void solve(const std::string& s)
{
    const size_t n = s.length(), m = index('z', 'z', 1) + 1;

    std::vector<unsigned> dp1(m), dp2(m);
    for (size_t i = 0; i < n; ++i) {
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                const size_t u = index(c1, c2, 0), v = index(c1, c2, 1);

                dp2[u] = dp1[u] + (i % 2 == 0 ? s[i] != c1 : s[i] != c2);
                dp2[v] = std::min(dp1[v] + (i % 2 == 1 ? s[i] != c1 : s[i] != c2), dp1[u]);
            }
        }

        std::swap(dp1, dp2);
    }

    unsigned k = ~0u;
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2)
            k = std::min(k, dp1[index(c1, c2, n % 2)]);
    }

    answer(k + n % 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
