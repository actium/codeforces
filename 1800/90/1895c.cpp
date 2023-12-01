#include <iostream>
#include <map>
#include <string>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::vector<unsigned> v(n);
    for (size_t i = 0; i < n; ++i) {
        for (const char c : s[i])
            v[i] += c - '0';
    }

    std::map<unsigned, unsigned> f[6];
    for (size_t i = 0; i < n; ++i)
        ++f[s[i].length()][v[i]];

    integer k = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t m = s[i].length();

        unsigned u = 0;
        for (size_t j = 0; j < m; ++j) {
            u += s[i][j] - '0';

            if (2 * u > v[i] && m < 2 * (j + 1))
                k += f[2 * (j + 1) - m][2 * u - v[i]];

            if (2 * (j + 1) < m && v[i] > 2 * u)
                k += f[m - 2 * (j + 1)][v[i] - 2 * u];
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
