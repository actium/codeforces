#include <iostream>
#include <vector>

#include <cmath>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

using density_set_t = std::vector<unsigned>;

void solve(const std::vector<unsigned>& x, const density_set_t& y, const density_set_t& z, unsigned a, unsigned b)
{
    double c = 0;
    for (const unsigned p1 : y) {
        for (const unsigned p2 : z)
            c = std::max(c, b * p1 / double(a * p2 + b * p1));
    }

    double r2 = 0, k = sqrt(c);
    for (const unsigned r1 : x)
        r2 = std::max(r2, k * r1);

    answer(r2);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    size_t m;
    std::cin >> m;

    density_set_t y(m);
    std::cin >> y;

    size_t k;
    std::cin >> k;

    density_set_t z(k);
    std::cin >> z;

    unsigned a, b;
    std::cin >> a >> b;

    solve(x, y, z, a, b);

    return 0;
}

