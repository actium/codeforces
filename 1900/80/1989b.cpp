#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length(), m = b.length();

    size_t c = n + m;
    for (size_t i = 0; i < m; ++i) {
        size_t k = 0;
        for (size_t j = 0; j < n && i + k < m; ++j)
            k += (a[j] == b[i+k]);

        c = std::min(c, n + m - k);
    }

    answer(c);
}

void test_case()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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
