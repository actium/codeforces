#include <algorithm>
#include <array>
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

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::vector<std::array<unsigned, 5>> f(n);
    for (size_t i = 0; i < n; ++i) {
        for (const char c : s[i])
            ++f[i][c-'a'];
    }

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    unsigned k = 0;
    for (size_t i = 0; i < 5; ++i) {
        std::sort(x.begin(), x.end(), [&](size_t a, size_t b) {
            return 2 * f[a][i] + s[b].length() > 2 * f[b][i] + s[a].length();
        });

        unsigned p = 0, r = 0, q = 0;
        for (auto it = x.begin(); it != x.end() && p + f[*it][i] > r + (s[*it].length() - f[*it][i]); ++it) {
            p += f[*it][i];
            r += s[*it].length() - f[*it][i];
            ++q;
        }

        k = std::max(k, q);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
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
