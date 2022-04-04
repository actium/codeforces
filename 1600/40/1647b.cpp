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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].length();

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            const unsigned k = -4 * '0' + b[i-1][j-1] + b[i-1][j] + b[i][j-1] + b[i][j];
            if (k == 3)
                return answer(false);
        }
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
