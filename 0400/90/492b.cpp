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

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(std::vector<size_t>& a, size_t l)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    size_t max_delta = 2 * a[0];
    for (size_t i = 1; i < n; ++i) {
        max_delta = std::max(max_delta, a[i] - a[i-1]);
    }
    max_delta = std::max(max_delta, 2 * (l - a.back()));

    answer(max_delta / 2.0);
}

int main()
{
    size_t n, l;
    std::cin >> n >> l;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a, l);

    return 0;
}

