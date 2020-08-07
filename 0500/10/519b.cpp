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

void answer(unsigned x, unsigned y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b, std::vector<unsigned>& c)
{
    const unsigned long long x = std::accumulate(a.cbegin(), a.cend(), 0ull);
    const unsigned long long y = std::accumulate(b.cbegin(), b.cend(), 0ull);
    const unsigned long long z = std::accumulate(c.cbegin(), c.cend(), 0ull);

    answer(x - y, y - z);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n-1);
    std::cin >> b;

    std::vector<unsigned> c(n-2);
    std::cin >> c;

    solve(a, b, c);

    return 0;
}

