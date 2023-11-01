#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    bool v[256] = {};
    for (const char c : s)
        v[c] = true;

    unsigned q = 0;
    for (char c = 'A'; c <= 'Z'; ++c)
        q += v[c] + v[c | 32];

    unsigned f[256] = {}, c = 0, k = ~0u;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for (c += (f[s[j]]++ == 0); c == q; c -= (--f[s[i++]] == 0))
            k = std::min<unsigned>(k, j - i + 1);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
