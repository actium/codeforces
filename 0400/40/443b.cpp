#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, unsigned k)
{
    const size_t n = s.length() + k;

    s.resize(n, '?');

    size_t q = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t p = 1; i + 2 * p <= n; ++p) {
            size_t j = 0;
            while (j < p && (s[i+j] == s[i+j+p] || s[i+j+p] == '?'))
                ++j;

            if (j == p)
                q = std::max(q, 2 * p);
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    unsigned k;
    std::cin >> k;

    solve(s, k);

    return 0;
}
