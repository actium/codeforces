#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const integer n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    integer s = 0;
    for (size_t i = 0; i < n; ++i)
        s += (2 * n - 4 * i - 1) * a[i];

    const integer d = std::gcd(n, s);

    answer(s / d, n / d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
