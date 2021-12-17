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
    std::cout << "YES" << '\n';

    for (const std::string x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<std::string>& a)
{
    const size_t n = a.size(), m = a[0].length();

    std::vector<std::string> b = a;

    const auto fill = [&](const char* x) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                b[i][j] = x[(i + j) % 2];

                if (a[i][j] != '.' && b[i][j] != a[i][j])
                    return false;
            }
        }
        return true;
    };

    if (fill("RW") || fill("WR"))
        return answer(b);

    no_answer();
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
