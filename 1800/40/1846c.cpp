#include <algorithm>
#include <iostream>
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

void solve(std::vector<std::vector<unsigned>>& t, unsigned h)
{
    const size_t n = t.size(), m = t[0].size();

    std::vector<std::pair<unsigned, unsigned long long>> xs(n, {0, 0});
    for (size_t i = 0; i < n; ++i) {
        std::sort(t[i].begin(), t[i].end());

        unsigned d = 0;
        for (size_t j = 0; j < m && d + t[i][j] <= h; ++j) {
            d += t[i][j];
            xs[i].second += d;
            ++xs[i].first;
        }
    }

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (xs[i].first < xs[0].first)
            continue;

        if (xs[i].first > xs[0].first || xs[i].second < xs[0].second)
            ++k;
    }

    answer(1 + k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned h;
    std::cin >> h;

    std::vector<std::vector<unsigned>> t(n, std::vector<unsigned>(m));
    std::cin >> t;

    solve(t, h);
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
