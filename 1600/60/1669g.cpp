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
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].length();

    for (size_t j = 0; j < m; ++j) {
        for (size_t i = n-1, o = n; ~i; --i) {
            if (b[i][j] == '*')
                std::swap(b[i][j], b[--o][j]);

            if (b[i][j] == 'o')
                o = i;
        }
    }

    answer(b);
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
