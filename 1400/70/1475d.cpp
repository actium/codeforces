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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned m)
{
    std::vector<unsigned> c[2] = { { 0 }, { 0 } };
    for (size_t i = 0, n = a.size(); i < n; ++i)
        c[b[i]-1].push_back(a[i]);

    for (size_t i = 0; i < 2; ++i) {
        std::sort(c[i].begin() + 1, c[i].end(), std::greater<unsigned>());

        for (size_t j = 1, k = c[i].size(); j < k; ++j)
            c[i][j] += c[i][j-1];
    }

    unsigned q = ~0u;
    for (size_t i = 0, k = c[0].size(); i < k; ++i) {
        if (c[0][i] < m) {
            const auto it = std::lower_bound(c[1].begin(), c[1].end(), m - c[0][i]);
            if (it != c[1].end())
                q = std::min<unsigned>(q, i + (it - c[1].begin()) * 2);
        } else {
            q = std::min<unsigned>(q, i);
        }
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

