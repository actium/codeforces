#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<size_t> x(n * m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            x[a[i][j]] = i;
    }

    for (size_t i = n; i < n * m; ++i) {
        if (x[i] != x[i-n])
            return no_answer();
    }

    x.resize(n);

    answer(x);
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
