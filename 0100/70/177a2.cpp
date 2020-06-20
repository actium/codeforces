#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();
    const size_t m = (n - 1) / 2;

    size_t s = 0;
    for (size_t i = 0; i < n; ++i) {
        s += a[i][i];
        s += a[i][n-1-i];
        s += a[m][i];
        s += a[i][m];
    }
    s -= 3 * a[m][m];

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    solve(a);

    return 0;
}

