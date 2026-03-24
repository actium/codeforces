#include <iostream>
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

void answer(integer x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::vector<unsigned>> s(1+n, std::vector<unsigned>(1+m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = m; j > 0; --j)
            s[i+1][j-1] = s[i+1][j] + a[i][j-1];
    }

    unsigned t = 0;
    for (size_t i = 1; i <= n; ++i)
        t += s[i][0];

    const integer k1 = t / 2, k2 = t - k1;

    std::string p;
    for (size_t i = 0, j = 0, q = k1; i < n || j < m; ) {
        if (i < n && s[i+1][j] <= q) {
            p.push_back('D');
            ++i;
            q -= s[i][j];
        } else {
            p.push_back('R');
            ++j;
        }
    }

    answer(k1 * k2, p);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);
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
