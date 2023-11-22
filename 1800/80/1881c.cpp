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

void solve(const std::vector<std::string>& a)
{
    const size_t n = a.size(), m = n / 2;

    unsigned k = 0;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = i; j + i + 1 < n; ++j) {
            unsigned s = 0, x = 'a';
            s += a[i][j];
            x = std::max<unsigned>(x, a[i][j]);
            s += a[j][n-1-i];
            x = std::max<unsigned>(x, a[j][n-1-i]);
            s += a[n-1-i][n-1-j];
            x = std::max<unsigned>(x, a[n-1-i][n-1-j]);
            s += a[n-1-j][i];
            x = std::max<unsigned>(x, a[n-1-j][i]);
            k += 4 * x - s;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
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
