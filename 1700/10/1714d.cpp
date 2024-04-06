#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

struct State {
    unsigned k = oo;
    size_t c;
    size_t s;
};

void solve(const std::string& t, const std::vector<std::string>& s)
{
    const size_t m = t.length(), n = s.size();

    std::vector<State> dp(1 + m);
    dp[0].k = 0;
    for (size_t i = 0; i < m && dp[i].k != oo; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (t.compare(i, s[j].length(), s[j]) != 0)
                continue;

            for (size_t k = 1; k <= s[j].length(); ++k) {
                if (dp[i].k + 1 < dp[i+k].k) {
                    dp[i+k].k = dp[i].k + 1;
                    dp[i+k].c = j;
                    dp[i+k].s = i;
                }
            }
        }
    }

    if (dp[m].k == oo)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> p;
    for (size_t i = m; i != 0; i = dp[i].s)
        p.emplace_back(1 + dp[i].c, 1 + dp[i].s);

    answer(p);
}

void test_case()
{
    std::string t;
    std::cin >> t;

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(t, s);
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
