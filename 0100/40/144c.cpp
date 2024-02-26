#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& p)
{
    const size_t n = s.length(), m = p.length();

    unsigned f[26] = {};
    for (const char c : p)
        ++f[c-'a'];

    unsigned k = 0;
    for (size_t i = 0, b = 0, q = 0; i < n; ++i) {
        if (i >= m) {
            if (s[i-m] == '?')
                --q;
            else
                b -= (++f[s[i-m]-'a'] > 0);
        }

        if (s[i] == '?')
            ++q;
        else
            b += (f[s[i]-'a']-- > 0);

        k += (b + q == m);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, p;
    std::cin >> s >> p;

    solve(s, p);

    return 0;
}
