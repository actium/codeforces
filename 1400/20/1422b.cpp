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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();
    const size_t m = a.front().size();

    unsigned long long k = 0;
    for (size_t i = 0; i < n/2; ++i) {
        for (size_t j = 0; j < m/2; ++j) {
            std::vector<unsigned> x = { a[i][j], a[n-1-i][j], a[n-1-i][m-1-j], a[i][m-1-j] };
            std::sort(x.begin(), x.end());

            const unsigned b = (x[1] + x[2]) / 2;
            k += abs(b - a[i][j]) + abs(b - a[n-1-i][j]) + abs(b - a[n-1-i][m-1-j]) + abs(b - a[i][m-1-j]);
        }
    }
    if (n % 2 == 1) {
        for (size_t j = 0; j < m/2; ++j) {
            const unsigned b = (a[n/2][j] + a[n/2][m-1-j]) / 2;
            k += abs(b - a[n/2][j]) + abs(b - a[n/2][m-1-j]);
        }
    }
    if (m % 2 == 1) {
        for (size_t i = 0; i < n/2; ++i) {
            const unsigned b = (a[i][m/2] + a[n-1-i][m/2]) / 2;
            k += abs(b - a[i][m/2]) + abs(b - a[n-1-i][m/2]);
        }
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

