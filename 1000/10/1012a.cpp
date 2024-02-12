#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

integer evaluate(unsigned dx, unsigned dy)
{
    return 1ull * dx * dy;
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size() / 2;

    std::sort(a.begin(), a.end());

    integer s = evaluate(a[n-1] - a[0], a[2*n-1] - a[n]);
    for (size_t i = 1; i < n; ++i)
        s = std::min(s, evaluate(a[2*n-1] - a[0], a[i+n-1] - a[i]));

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a);

    return 0;
}
