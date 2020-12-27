#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::string& s, unsigned k)
{
    unsigned f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    std::vector<size_t> x;
    for (size_t i = 0; i < 26; ++i) {
        if (f[i] > 0)
            x.push_back(i);
    }

    std::sort(x.begin(), x.end(), [&f](size_t a, size_t b) { return f[a] > f[b]; });

    while (!x.empty() && f[x.back()] <= k) {
        k -= f[x.back()];
        f[x.back()] = 0;
        x.pop_back();
    }

    std::string t;
    for (const char c : s) {
        if (f[c - 'a'] != 0)
            t.push_back(c);
    }

    answer(x.size(), t);
}

int main()
{
    std::string s;
    std::cin >> s;

    unsigned k;
    std::cin >> k;

    solve(s, k);

    return 0;
}

