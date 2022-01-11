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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<int> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = a[i] - b[i];

    std::sort(c.begin(), c.end());

    integer k = 0;
    for (auto it = c.cbegin(); it != c.cend(); ++it)
        k += std::distance(std::lower_bound(std::next(it), c.cend(), 1 - *it), c.cend());

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
