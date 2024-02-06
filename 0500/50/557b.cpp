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

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned w)
{
    const size_t n = a.size() / 2;

    std::sort(a.begin(), a.end());

    const double b = std::min<double>(a[0], a[n] / 2.0);
    answer(std::min<double>(3 * b * n, w));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned w;
    std::cin >> w;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a, w);

    return 0;
}
