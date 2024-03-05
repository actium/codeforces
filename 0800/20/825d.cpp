#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    unsigned f[27] = {};
    for (const char c : s)
        ++f[c != '?' ? c - 'a' : 26];

    unsigned g[26] = {};
    for (const char c : t)
        ++g[c-'a'];

    const auto check = [&](unsigned k) {
        unsigned q = f[26];
        for (size_t i = 0; i < 26; ++i) {
            if (g[i] * k <= f[i])
                continue;

            const unsigned d = g[i] * k - f[i];
            if (d > q)
                return false;

            q -= d;
        }
        return true;
    };

    unsigned lb = 0, ub = s.length() / t.length() + 1;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    std::string p;
    for (char c : s) {
        if (c == '?') {
            c = 'a';
            for (size_t i = 0; i < 26; ++i) {
                if (f[i] < g[i] * lb) {
                    c += i;
                    ++f[i];
                    break;
                }
            }
        }

        p.push_back(c);
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
