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
    std::cout << std::fixed << v << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    double w = 0;
    for (size_t i = 0; i < k; ++i)
        w += a[i];

    double s = w;
    for (size_t i = k; i < n; ++i) {
        w += int(a[i] - a[i-k]);
        s += w;
    }

    answer(s / (n - k + 1));
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

