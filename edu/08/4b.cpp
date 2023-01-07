#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& x)
{
    const size_t n = x.size();

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i) {
        if (x[i][i] != 0)
            return no_answer();

        for (size_t j = 0; j < n; ++j) {
            if (x[i][j] != x[j][i])
                return no_answer();

            d[i] += x[i][j];
        }
    }

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> x(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            std::cin >> x[i][j];
    }

    solve(x);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
