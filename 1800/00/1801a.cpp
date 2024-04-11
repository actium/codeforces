#include <iostream>
#include <vector>

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << v.size() * v[0].size() << '\n';

    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void solve(size_t n, size_t m)
{
    const unsigned d = 1 << __builtin_clz(1) - __builtin_clz(m) + 1;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            a[i][j] = i * d + j;
    }

    answer(a);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
