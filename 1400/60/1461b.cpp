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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& c)
{
    const size_t n = c.size(), m = c[0].length();

    std::vector<std::vector<unsigned>> p(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0, k = 0; j < m-1; ++j) {
            if (c[i][j] == '*')
                p[i][j] = k++;
            else
                k = 0;
        }
        for (size_t j = m-1, k = 0; j > 0; --j) {
            p[i][j] = std::min<unsigned>(p[i][j], k++);

            if (c[i][j] != '*')
                k = 0;
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (c[i][j] != '*')
                continue;

            for (size_t h = 0; i + h < n && p[i+h][j] >= h; ++h)
                ++k;
        }
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

