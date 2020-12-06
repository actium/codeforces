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
    const size_t n = g.size();

    unsigned f[3] = {}, k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (g[i][j] == 'X') {
                ++f[(i + j) % 3];
                ++k;
            }
        }
    }

    size_t c = 0;
    for (k /= 3; f[c] > k; ++c);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if ((i + j) % 3 == c && g[i][j] == 'X')
                g[i][j] = 'O';
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

