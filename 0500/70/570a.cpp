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
    std::cout << 1+v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a, size_t n)
{
    const size_t m = a.size();

    std::vector<unsigned> f(n);
    for (size_t i = 0; i < m; ++i) {
        size_t w = 0;
        for (size_t j = 1; j < n; ++j) {
            if (a[i][j] > a[i][w])
                w = j;
        }
        ++f[w];
    }

    size_t w = 0;
    for (size_t j = 1; j < n; ++j) {
        if (f[j] > f[w])
            w = j;
    }

    answer(w);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(m, std::vector<unsigned>(n));
    std::cin >> a;

    solve(a, n);

    return 0;
}

