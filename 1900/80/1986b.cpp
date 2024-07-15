#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    const auto check = [&](size_t r, size_t c) {
        std::vector<unsigned> q;
        if (r > 0)
            q.push_back(a[r-1][c]);
        if (r + 1 < n)
            q.push_back(a[r+1][c]);
        if (c > 0)
            q.push_back(a[r][c-1]);
        if (c + 1 < m)
            q.push_back(a[r][c+1]);

        const auto it = std::max_element(q.begin(), q.end());
        return q.empty() || a[r][c] < *it ? a[r][c] : *it;
    };

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            a[i][j] = check(i, j);
    }

    answer(a);
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
