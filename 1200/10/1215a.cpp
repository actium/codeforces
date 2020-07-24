#include <array>
#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::array<unsigned, 2>& a, std::array<unsigned, 2>& k, unsigned n)
{
    if (k[0] > k[1]) {
        std::swap(a[0], a[1]);
        std::swap(k[0], k[1]);
    }

    const unsigned b1 = std::min(a[0] * (k[0] - 1), n);
    const unsigned b2 = std::min(a[1] * (k[1] - 1), n - b1);
    const unsigned b = n - (b1 + b2);

    const unsigned c1 = std::min(a[0], n / k[0]);
    const unsigned c2 = std::min(a[1], (n - c1 * k[0]) / k[1]);
    const unsigned c = c1 + c2;

    answer(b, c);
}

int main()
{
    std::array<unsigned, 2> a;
    std::cin >> a[0] >> a[1];

    std::array<unsigned, 2> k;
    std::cin >> k[0] >> k[1];

    unsigned n;
    std::cin >> n;

    solve(a, k, n);

    return 0;
}

