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

void solve(const std::vector<std::string>& c)
{
    constexpr char t[4] = { 'v', 'i', 'k', 'a' };

    const size_t n = c.size(), m = c[0].size();

    size_t k = 0;
    for (size_t j = 0; j < m && k < 4; ++j) {
        for (size_t i = 0; i < n; ++i) {
            if (c[i][j] == t[k]) {
                ++k;
                break;
            }
        }
    }

    answer(k == 4);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> c(n);
    std::cin >> c;

    solve(c);
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
