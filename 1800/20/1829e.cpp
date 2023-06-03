#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned traverse(std::vector<std::vector<unsigned>>& a, size_t r, size_t c)
{
    const size_t n = a.size(), m = a[0].size();
    if (r >= n || c >= m || a[r][c] == 0)
        return 0;

    const unsigned h = a[r][c];
    a[r][c] = 0;
    return h + traverse(a, r-1, c) + traverse(a, r, c+1) + traverse(a, r+1, c) + traverse(a, r, c-1);
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    unsigned h = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            h = std::max(h, traverse(a, i, j));
    }

    answer(h);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
