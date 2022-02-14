#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << "YES" << '\n';

    for (const std::vector<unsigned>& a : v) {
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
    std::cout << "NO" << '\n';
}

void solve(size_t n, size_t k)
{
    if (n % 2 == 1 && k != 1)
        return no_answer();

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(k));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j)
            a[i][j] = 1 + i + j * n;
    }

    answer(a);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
