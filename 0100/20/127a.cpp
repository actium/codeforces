#include <iostream>
#include <vector>

#include <cmath>

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

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(const std::vector<std::pair<int, int>>& a, size_t k)
{
    const size_t n = a.size();

    double d = 0;
    for (size_t i = 1; i < n; ++i) {
        d += hypot(a[i].first - a[i-1].first, a[i].second - a[i-1].second);
    }

    answer(k * d / 50);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

