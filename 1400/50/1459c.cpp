#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<integer>& a, const std::vector<integer>& b)
{
    const size_t n = a.size(), m = b.size();

    std::sort(a.begin(), a.end());

    integer g = 0;
    for (size_t i = 1; i < n; ++i)
        g = std::gcd(g, a[i] - a[i-1]);

    std::vector<integer> x(m);
    for (size_t i = 0; i < m; ++i)
        x[i] = std::gcd(a[0] + b[i], g);

    answer(x);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<integer> a(n);
    std::cin >> a;

    std::vector<integer> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

