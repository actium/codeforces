#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(unsigned n, unsigned m, unsigned k, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    unsigned count = 1;

    std::vector<bool> painted_rows(n), painted_columns(m);
    unsigned painted_row_count = 0, painted_column_count = 0;
    for (auto it = r.rbegin(); it != r.rend(); ++it) {
        if (painted_row_count < n && painted_column_count < m && (!painted_rows[it->first-1] || !painted_columns[it->second-1]))
            count = 1ull * count * k % M;

        painted_row_count += !painted_rows[it->first-1];
        painted_column_count += !painted_columns[it->second-1];

        painted_rows[it->first-1] = true;
        painted_columns[it->second-1] = true;
    }

    answer(count);
}

void test_case()
{
    unsigned n, m, k;
    std::cin >> n >> m >> k;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(n, m, k, r);
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
