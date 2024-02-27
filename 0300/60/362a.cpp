#include <array>
#include <iostream>
#include <string>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<std::string, 8>& g)
{
    std::pair<size_t, size_t> p, q;
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 8; ++j) {
            if (g[i][j] == 'K') {
                q = std::make_pair(i, j);
                std::swap(p, q);
            }
        }
    }

    const size_t dr = std::max(p.first, q.first) - std::min(p.first, q.first);
    const size_t dc = std::max(p.second, q.second) - std::min(p.second, q.second);

    answer(dr % 4 == 0 && dc % 4 == 0);
}

void test_case()
{
    std::array<std::string, 8> g;
    std::cin >> g;

    solve(g);
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
