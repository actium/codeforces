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

void answer(const std::vector<std::string>& v)
{
    for (const std::string x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::string>& g)
{
    constexpr char s[2] = { 'X', 'O' };

    const size_t n = g.size();

    unsigned f[3][2] = {}, k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t q = 0; q < 2; ++q) {
                if (g[i][j] == s[q]) {
                    ++f[(i + j) % 3][q];
                    ++k;
                }
            }
        }
    }

    size_t c[2] = {};
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (i != j && f[i][0] + f[j][1] <= k/3) {
                c[0] = i;
                c[1] = j;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t q = 0; q < 2; ++q) {
                if ((i + j) % 3 == c[q] && g[i][j] == s[q])
                    g[i][j] = 'X' + 'O' - s[q];
            }
        }
    }

    answer(g);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

