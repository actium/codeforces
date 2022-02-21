#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned k)
{
    const size_t n = s.length();

    const auto f = [n, &s](char c, unsigned k) {
        unsigned q = 0;
        for (size_t i = 0, j = 0; j < n; ++j) {
            k -= (s[j] != c);

            while (k == 0 && s[j] != c)
                k += (s[i++] != c);

            q = std::max<unsigned>(q, j - i + 1);
        }
        return q;
    };

    answer(std::max(f('a', k+1), f('b', k+1)));
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

