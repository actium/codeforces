#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::string>& s)
{
    const size_t n = s.size(), k = s[0].length();

    std::sort(s.begin(), s.end());

    unsigned q = 0;

    std::string p;
    for (size_t i = 2; i < n; ++i) {
        for (size_t j = 1; j < i; ++j) {
            p = s[i];

            for (size_t x = 0; x < k; ++x) {
                if (s[i][x] != s[j][x])
                    p[x] ^= s[j][x] ^ 'S' ^ 'E' ^ 'T';
            }

            const auto r = std::equal_range(s.begin(), s.begin() + j, p);
            q += r.second - r.first;
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
