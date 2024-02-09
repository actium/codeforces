#include <iostream>
#include <vector>

#include <cmath>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<double>& v)
{
    const char* separator = "";
    for (const double x : v) {
        std::cout << separator << std::fixed << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& x, unsigned r)
{
    const size_t n = x.size();

    std::vector<double> y(n, r);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            const unsigned dx = x[i] < x[j] ? x[j] - x[i] : x[i] - x[j];
            if (dx <= 2 * r)
                y[i] = std::max(y[i], y[j] + sqrt(4 * r * r - dx * dx));
        }
    }

    answer(y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned r;
    std::cin >> r;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, r);

    return 0;
}
