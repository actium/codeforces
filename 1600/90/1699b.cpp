#include <iostream>
#include <vector>

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

void solve(size_t n, size_t m)
{
    std::vector<std::vector<unsigned>> v(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; i += 2) {
        for (size_t j = 0; j < m; j += 2) {
            const unsigned c = i / 2 % 2 ^ j / 2 % 2;
            v[i+0][j+0] = c ^ 0;
            v[i+0][j+1] = c ^ 1;
            v[i+1][j+0] = c ^ 1;
            v[i+1][j+1] = c ^ 0;
        }
    }

    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
