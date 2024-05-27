#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include <cstdint>
#include <ctime>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

uint64_t h[300000];

void initialize()
{
    std::mt19937_64 g(time(nullptr));

    for (size_t i = 0; i < 300000; ++i)
        h[i] = g();
}

void solve(std::vector<std::string>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::pair<uint64_t, size_t>> s;
    for (size_t j = 0; j < m; ++j) {
        uint64_t v = 0;
        for (size_t i = 0; i < n; ++i) {
            if (a[i][j] == '1')
                v ^= h[i];
        }

        for (size_t i = 0; i < n; ++i)
            s.emplace_back(v ^ h[i], i * m + j);
    }

    std::sort(s.begin(), s.end());

    std::pair<size_t, size_t> x = { 0, 0 };
    for (size_t i = 0, j = 0; i < s.size(); i = j) {
        while (j < s.size() && s[j].first == s[i].first)
            ++j;

        if (j - i > x.first) {
            x.first = j - i;
            x.second = s[i].second;
        }
    }

    std::string w;
    for (size_t i = 0; i < n; ++i)
        w.push_back(a[i][x.second % m] ^ (i == x.second / m));

    answer(x.first, w);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
