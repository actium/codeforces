#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<std::string, std::string>>& a)
{
    unsigned k = 0;

    std::map<std::string, unsigned> dp;
    dp["polycarp"] = 1;
    for (const auto& x : a) {
        std::string s = x.second;
        std::transform(s.begin(), s.end(), s.begin(), tolower);

        std::string t = x.first;
        std::transform(t.begin(), t.end(), t.begin(), tolower);

        dp[t] = dp[s] + 1;
        k = std::max(k, dp[t]);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string>> a(n);
    for (auto& v : a) {
        std::string x;
        std::cin >> v.first >> x >> v.second;
    }

    solve(a);

    return 0;
}

