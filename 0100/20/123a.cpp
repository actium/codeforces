#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::string& v)
{
    std::cout << "YES" << '\n';
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<bool> v(n);
    for (unsigned p = 2; 2 * p <= n; ++p) {
        for (size_t i = p - 1; i < n; i += p)
            v[i] = true;
    }

    unsigned f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    std::string t(n, ' ');
    for (size_t i = 0, x = std::max_element(f, f + 26) - f; i < n; ++i) {
        if (!v[i])
            continue;

        if (f[x]-- == 0)
            return no_answer();

        t[i] = 'a' + x;
    }
    for (size_t i = 0; i < n; ++i) {
        if (t[i] == ' ') {
            const size_t x = std::find_if(f, f + 26, [](unsigned q) { return q > 0; }) - f;
            t[i] = 'a' + x;
            --f[x];
        }
    }

    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

