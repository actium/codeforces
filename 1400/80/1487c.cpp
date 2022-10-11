#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<int>>& v)
{
    const size_t n = v.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 1+i; j < n; ++j) {
            std::cout << v[i][j] << ' ';
        }
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<std::vector<int>> s(n, std::vector<int>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 1; j < (n + 1) / 2; ++j) {
            s[i][(i+j)%n] = 1;
            s[i][(n/2+i+j)%n] = -1;
        }
    }

    answer(s);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
