#include <array>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& u : v) {
        const char* separator = "";
        for (const unsigned x : u) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a, const std::string& s)
{
    const size_t n = a.size();

    std::pair<unsigned, unsigned> d[3] = { { 0, 0 }, { 1, 0 }, { 2, 0 } };
    for (const char c : s) {
        if (c == 'U')
            d[0].second = (n + d[0].second - 1) % n;

        if (c == 'D')
            d[0].second = (n + d[0].second + 1) % n;

        if (c == 'L')
            d[1].second = (n + d[1].second - 1) % n;

        if (c == 'R')
            d[1].second = (n + d[1].second + 1) % n;

        if (c == 'I')
            std::swap(d[1], d[2]);

        if (c == 'C')
            std::swap(d[0], d[2]);
    }

    std::vector<std::array<unsigned, 3>> t(n * n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            t[i * n + j] = { i, j, a[i][j] - 1 };
    }

    for (const auto& x : t) {
        const size_t i = (x[d[0].first] + d[0].second) % n;
        const size_t j = (x[d[1].first] + d[1].second) % n;
        a[i][j] = (x[d[2].first] + d[2].second) % n + 1;
    }

    answer(a);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(a, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

