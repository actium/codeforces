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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& b, size_t r, size_t c)
{
    const size_t n = b.size(), m = b[0].length();

    if (b[r-1][c-1] == 'B')
        return answer(0);

    size_t y = n;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] != 'B')
                continue;

            if (i == r-1 || j == c-1)
                return answer(1);

            y = i;
        }
    }

    if (y < n)
        return answer(2);

    no_answer();
}

void test_case()
{
    size_t n, m, r, c;
    std::cin >> n >> m >> r >> c;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b, r, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
