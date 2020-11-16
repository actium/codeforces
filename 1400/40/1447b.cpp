#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<int>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    unsigned k = 0, s = 0, b = 100;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            k += (a[i][j] < 0);
            s += abs(a[i][j]);
            b = std::min<unsigned>(b, abs(a[i][j]));
        }
    }

    answer(k % 2 == 0 ? s : s - 2 * b);
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

