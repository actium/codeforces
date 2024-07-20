#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, unsigned p)
{
    const size_t n = s.length(), m = n / 2;

    if (p > m) {
        std::reverse(s.begin(), s.end());
        p = n - p + 1;
    }

    unsigned k = 0;
    {
        std::vector<size_t> x;
        for (size_t i = 0; i < m; ++i) {
            const unsigned u = (s[i] + 26 - s[n-1-i]) % 26;
            if (u != 0) {
                x.push_back(i);
                k += std::min(u, 26 - u);
            }
        }

        if (!x.empty()) {
            --p;

            if (x.back() < p)
                k += p - x.front();

            if (p < x.front())
                k += x.back() - p;

            if (p >= x.front() && p <= x.back())
                k += 2 * std::min(p - x.front(), x.back() - p) + std::max(p - x.front(), x.back() - p);
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned p;
    std::cin >> p;

    std::string s;
    std::cin >> s;

    solve(s, p);

    return 0;
}
