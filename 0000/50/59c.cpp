#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "IMPOSSIBLE" << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length(), x = n / 2;

    bool v[26] = {};
    for (const char c : s) {
        if (c != '?')
            v[c-'a'] = true;
    }

    for (size_t i = (n - 1) / 2, j = n / 2, p = k - 1; j < n; --i, ++j) {
        if (s[i] == '?' && s[j] == '?') {
            while (p > 0 && v[p])
                --p;

            s[i] = 'a' + p;
            s[j] = 'a' + p;
            v[p] = true;
        }

        if (s[i] == '?')
            s[i] = s[j];

        if (s[j] == '?')
            s[j] = s[i];

        if (s[i] != s[j])
            return no_answer();
    }

    for (size_t i = 0; i < k; ++i) {
        if (!v[i])
            return no_answer();
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}
