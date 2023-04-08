#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
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
    const size_t m = a.size();

    std::vector<unsigned> p(m);

    bool v[50000] = {};
    for (size_t i = m - 1; ~i != 0; --i) {
        const size_t n = a[i].size();

        size_t j = 0;
        while (j < n && v[a[i][j] - 1])
            ++j;

        if (j == n)
            return no_answer();

        for (p[i] = a[i][j]; j < n; ++j)
            v[a[i][j] - 1] = true;
    }

    answer(p);
}

void test_case()
{
    size_t m;
    std::cin >> m;

    std::vector<std::vector<unsigned>> a(m);
    for (size_t i = 0; i < m; ++i) {
        size_t n;
        std::cin >> n;

        a[i].resize(n);
        std::cin >> a[i];
    }

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
