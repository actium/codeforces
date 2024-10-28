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

void solve(const std::vector<std::vector<int>>& a)
{
    const size_t n = a.size();

    std::vector<int> c(2 * n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            c[n+i-j] = std::min(c[n+i-j], a[i][j]);
    }

    unsigned k = 0;
    for (const int x : c)
        k -= x;

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
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
