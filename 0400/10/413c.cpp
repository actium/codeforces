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

void solve(const std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    std::sort(b.begin(), b.end(), [&](unsigned x, unsigned y) { return a[x-1] > a[y-1]; });

    integer s = 0;
    for (const unsigned x : a)
        s += x;

    for (const unsigned x : b)
        s -= a[x-1];

    for (const unsigned x : b)
        s += std::max<integer>(s, a[x-1]);

    answer(s);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
