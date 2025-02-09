#include <iostream>
#include <vector>

using integer = long long;

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
        output << separator << x;
        separator = " ";
    }

    return output;
}

void answer(const std::vector<std::vector<integer>>& v)
{
    for (const std::vector<integer>& x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::vector<integer>>& a, const std::string& s)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<integer> row_sums(n), column_sums(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            row_sums[i] += a[i][j];
            column_sums[j] += a[i][j];
        }
    }

    const auto update = [&](size_t i, size_t j, integer v) {
        a[i][j] = v;
        row_sums[i] += v;
        column_sums[j] += v;
    };

    size_t i = 0, j = 0;
    for (const char c : s) {
        if (c == 'R') {
            update(i, j, -column_sums[j]);
            ++j;
        } else {
            update(i, j, -row_sums[i]);
            ++i;
        }
    }

    answer(a);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<integer>> a(n, std::vector<integer>(m));
    std::cin >> a;

    solve(a, s + 'X');
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
