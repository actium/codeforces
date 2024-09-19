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

void solve(std::vector<unsigned>& a, unsigned k, unsigned m)
{
    using integer = unsigned long long;

    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    double s = 0;
    for (const unsigned x : a)
        s += x;

    double v = (s + std::min<integer>(m, 1ull * n * k)) / n;
    for (size_t i = 1; i <= std::min<unsigned>(n-1, m); ++i) {
        s -= a[i-1];
        v = std::max(v, (s + std::min<integer>(m - i, 1ull * (n - i) * k)) / (n - i));
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k, m;
    std::cin >> k >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, m);

    return 0;
}
