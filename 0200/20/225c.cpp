#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

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

void solve(const std::vector<std::string>& s, size_t x, size_t y)
{
    const size_t n = s.size(), m = s[0].size();

    std::vector<unsigned> t(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            t[j] += (s[i][j] == '#');
    }

    std::vector<unsigned> dp1(y+1, oo), dp2(y+1, oo);
    dp1[0] = 0;
    dp2[0] = 0;
    for (size_t i = 0; i < m; ++i) {
        std::vector<unsigned> ndp1(y+1, oo), ndp2(y+1, oo);
        for (size_t j = 1; j <= y; ++j) {
            ndp1[j] = dp1[j-1] + t[i];
            ndp2[j] = dp2[j-1] + (n - t[i]);

            if (j >= x) {
                ndp1[1] = std::min<unsigned>(ndp1[1], dp2[j] + t[i]);
                ndp2[1] = std::min<unsigned>(ndp2[1], dp1[j] + (n - t[i]));
            }
        }

        std::swap(dp1, ndp1);
        std::swap(dp2, ndp2);
    }

    unsigned k = oo;
    for (size_t i = x; i <= y; ++i) {
        k = std::min(k, dp1[i]);
        k = std::min(k, dp2[i]);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, x, y;
    std::cin >> n >> m >> x >> y;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, x, y);

    return 0;
}
