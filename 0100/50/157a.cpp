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

void solve(const std::vector<std::vector<int>>& a)
{
    const size_t n = a.size();

    std::vector<size_t> c(n);
    std::vector<size_t> r(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }

    size_t k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (c[i] > r[j])
                ++k;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::cin >> a;

    solve(a);

    return 0;
}

