#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    unsigned f[26] = {};
    for (const char c : s)
        ++f[c-'a'];

    std::vector<std::pair<unsigned, size_t>> p(26);
    for (size_t i = 0; i < 26; ++i) {
        p[i].first = f[i];
        p[i].second = i;
    }

    std::sort(p.begin(), p.end(), std::greater<std::pair<unsigned, size_t>>());

    std::pair<unsigned, unsigned> x = { n, n };

    const auto check = [&](unsigned q) {
        const size_t k = n / q;
        if (k > 26)
            return;

        unsigned d = 0;
        for (size_t i = 0; i < 26; ++i) {
            const unsigned u = (i < k ? q : 0);
            if (p[i].first > u)
                d += p[i].first - u;
        }

        x = std::min(x, std::make_pair(d, q));
    };

    for (unsigned i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            check(i);
            check(n / i);
        }
    }

    const unsigned k = n / x.second;

    unsigned u[26] = {};
    for (size_t i = 0; i < k; ++i) {
        if (p[i].first >= x.second)
            f[p[i].second] = x.second;
        else
            u[p[i].second] = x.second - p[i].first;
    }
    for (size_t i = k; i < 26; ++i)
        f[p[i].second] = 0;

    for (size_t i = 0, j = 0; i < n; ++i) {
        const size_t c = s[i] - 'a';
        if (f[c] != 0) {
            --f[c];
            continue;
        }

        while (u[j] == 0)
            ++j;

        s[i] = 'a' + j;
        --u[j];
    }

    answer(x.first, s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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