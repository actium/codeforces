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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& a, size_t x, size_t y)
{
    size_t cost = 0;
    if (2 * x <= y) {
        for (const std::string& row : a) {
            for (const char c : row) {
                if (c == '.')
                    cost += x;
            }
        }
    } else {
        const size_t m = a.front().length();
        for (const std::string& row : a) {
            for (size_t i = 0; i < m; ++i) {
                if (row[i] == '*')
                    continue;

                if (i + 1 < m && row[i+1] == '.') {
                    cost += y;
                    ++i;
                } else {
                    cost += x;
                }
            }
        }
    }

    answer(cost);
}

void test_case()
{
    size_t n, m, x, y;
    std::cin >> n >> m >> x >> y;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a, x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

