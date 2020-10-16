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

void answer(unsigned v)
{
    std::cout << 1 + v << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& q)
{
    const size_t n = a.size();

    for (size_t i = 1; i < n; ++i)
        a[i] += a[i-1];

    for (const unsigned x : q)
        answer(std::lower_bound(a.cbegin(), a.cend(), x) - a.cbegin());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}

