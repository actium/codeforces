#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double v)
{
    std::cout.precision(9);

    std::cout << std::fixed << v << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    for (size_t i = 1; i < n; ++i)
        a[i] += a[i-1];

    double x = 0;
    for (size_t i = k-1; i < n; ++i) {
        x = std::max(x, a[i] / (i + 1.0));

        for (size_t j = 0; j + k <= i; ++j)
            x = std::max(x, double(a[i] - a[j]) / (i - j));
    }

    answer(x);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

