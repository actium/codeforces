#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void solve(size_t n, size_t m, size_t k)
{
    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    for (size_t i = 0, x = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            a[i][j] = 1 + x++ % k;
    }

    if (m % k == 0) {
        for (size_t i = 1; i < n; i += 2)
            std::rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
    }

    answer(a);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
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
