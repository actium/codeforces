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

integer count(const std::vector<unsigned>& p, unsigned begin, unsigned end, unsigned a, unsigned b)
{
    const size_t k = std::upper_bound(p.begin(), p.end(), end) - std::upper_bound(p.begin(), p.end(), begin);
    if (k == 0)
        return a;

    const integer d = end - begin;
    if (d == 1)
        return b * k;

    const unsigned mid = (begin + end) / 2;
    return std::min(count(p, begin, mid, a, b) + count(p, mid, end, a, b), b * k * d);
}

void solve(size_t n, std::vector<unsigned>& p, unsigned a, unsigned b)
{
    std::sort(p.begin(), p.end());

    answer(count(p, 0, 1 << n, a, b));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> p(k);
    std::cin >> p;

    solve(n, p, a, b);

    return 0;
}
