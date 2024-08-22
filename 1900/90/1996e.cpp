#include <iostream>
#include <string>
#include <vector>

constexpr unsigned M = 1'000'000'007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    {
        std::vector<size_t> p[2], q(1+n);
        for (size_t i = 0; i < n; ++i) {
            const size_t x = s[i] - '0';
            p[x].push_back(i);

            if (!p[x^1].empty()) {
                const size_t b = p[x^1].back();
                p[x^1].pop_back();

                q[i+1] = (q[b] + b + 1) % M;
                k = (k + 1ull * q[i+1] * (n - i)) % M;
            }
        }
    }
    answer(k);
}

void test_case()
{
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
