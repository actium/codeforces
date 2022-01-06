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

void answer(const std::string& x)
{
    std::cout << x << std::endl;
}

void solve(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
    const size_t n = a.size(), m = a[0].size();

    std::string x = a[0];
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            x[j] ^= a[i][j];
    }
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            x[j] ^= b[i-1][j];
    }

    answer(x);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n), b(n-1);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
