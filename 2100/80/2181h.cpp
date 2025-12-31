#include <iostream>
#include <numeric>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned w, unsigned h, unsigned d, unsigned n)
{
    const unsigned g1 = std::gcd(n, w);
    n /= g1;

    const unsigned g2 = std::gcd(n, h);
    n /= g2;

    const unsigned g3 = std::gcd(n, d);
    n /= g3;

    n == 1 ? answer(g1-1, g2-1, g3-1) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned w, h, d;
    std::cin >> w >> h >> d;

    unsigned n;
    std::cin >> n;

    solve(w, h, d, n);

    return 0;
}
