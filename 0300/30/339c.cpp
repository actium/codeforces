#include <array>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s, unsigned m)
{
    std::vector<std::array<std::array<std::pair<unsigned, unsigned>, 11>, 11>> dp(m);
    for (unsigned w = 1; w <= 10; ++w) {
        if (s[w-1] == '1')
            dp[0][w][w] = { w, ~0u };
    }

    for (unsigned i = 1; i < m; ++i) {
        for (unsigned b = 1; b < 10; ++b) {
            for (unsigned v = 1; v <= 10; ++v) {
                for (unsigned w = b+1; w <= 10; ++w) {
                    if (w != v && s[w-1] == '1' && dp[i-1][v][b].second != 0)
                        dp[i][w][w-b] = { v, b };
                }
            }
        }
    }

    const auto restore_answer = [&](unsigned b, unsigned w) {
        std::vector<unsigned> s(m);
        for (unsigned i = 0; i < m; ++i) {
            s[m-1-i] = w;

            const std::pair<unsigned, unsigned>& e = dp[m-1-i][w][b];
            w = e.first;
            b = e.second;
        }
        s[0] = w;
        return s;
    };

    for (unsigned b = 1; b <= 10; ++b) {
        for (unsigned w = 1; w <= 10; ++w) {
            if (dp[m-1][w][b].second != 0)
                return answer(restore_answer(b, w));
        }
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    unsigned m;
    std::cin >> m;

    solve(s, m);

    return 0;
}
