#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

bool test_row(const std::vector<int>& row)
{
    for (const int c : row) {
        if (c == 1)
            return false;
    }
    return true;
}

bool test_column(const std::vector<std::vector<int>>& a, size_t j)
{
    for (const auto& row : a) {
        if (row[j] == 1)
            return false;
    }
    return true;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "Ashish", "Vivek" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::vector<int>>& a)
{
    size_t rc = 0;
    for (const std::vector<int>& row : a) {
        if (test_row(row))
            ++rc;
    }

    size_t cc = 0;
    for (size_t j = 0; j < a[0].size(); ++j) {
        if (test_column(a, j))
            ++cc;
    }

    const size_t tc = std::min(rc, cc);
    answer(tc % 2 == 0);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

