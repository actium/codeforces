#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(unsigned n, unsigned k, unsigned r, unsigned c)
{
    --r, --c;

    std::vector<std::string> g(n, std::string(n, '.'));
    for (size_t i = 0; i < n; i += k) {
        for (size_t j = 0; j < n; ++j)
            g[(r+j)%n][(c+i+j)%n] = 'X';
    }

    answer(g);
}

void test_case()
{
    unsigned n, k, r, c;
    std::cin >> n >> k >> r >> c;

    solve(n, k, r, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
