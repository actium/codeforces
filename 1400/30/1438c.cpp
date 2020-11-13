#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v) {
        const char* separator = "";
        for (const unsigned y : x) {
            std::cout << separator << y;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if ((i + j) % 2 != a[i][j] % 2)
                ++a[i][j];
        }
    }

    answer(a);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

