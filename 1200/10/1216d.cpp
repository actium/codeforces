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

void answer(unsigned long long x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned u = 0;
    for (const unsigned x : a)
        u = std::max(u, x);

    unsigned z = 0;
    for (const unsigned x : a)
        z = std::gcd(z, u - x);

    unsigned long long y = 0;
    for (const unsigned x : a)
        y += (u - x) / z;

    answer(y, z);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

