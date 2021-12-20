#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const auto& a : v) {
        const char* separator = "";
        for (const unsigned x : a) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n)
{
    if (n == 2)
        return no_answer();

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            a[i][(j+i)%n] = 1 + i + j * n;
    }

    answer(a);
}

void test_case()
{
    size_t n;
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
