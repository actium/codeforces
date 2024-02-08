#include <iostream>
#include <queue>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size() + 1;

    std::vector<unsigned> d(n);
    for (size_t i = 1; i < n; ++i)
        d[i] = d[p[i-1]-1] + 1;

    std::vector<unsigned> k(n);
    for (const unsigned x : d)
        ++k[x];

    unsigned s = 0;
    for (const unsigned x : k)
        s += x % 2;

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n - 1);
    std::cin >> p;

    solve(p);

    return 0;
}
