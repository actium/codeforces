#include <algorithm>
#include <iostream>
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

void solve(size_t n, size_t m, size_t k, std::vector<unsigned>& a)
{
    std::vector<std::vector<int>> p(1+n+1, std::vector<int>(1+m+1));
    for (size_t i = 1; i + k - 1 <= n; ++i) {
        for (size_t j = 1; j + k - 1 <= m; ++j) {
            ++p[i][j];
            --p[i][j+k];
            --p[i+k][j];
            ++p[i+k][j+k];
        }
    }

    std::vector<unsigned> q;
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            q.push_back(p[i][j]);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<unsigned>());
    std::sort(q.begin(), q.end(), std::greater<unsigned>());

    integer x = 0;
    for (size_t i = 0; i < a.size(); ++i)
        x += 1ull * a[i] * q[i];

    answer(x);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    size_t w;
    std::cin >> w;

    std::vector<unsigned> a(w);
    std::cin >> a;

    solve(n, m, k, a);
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
