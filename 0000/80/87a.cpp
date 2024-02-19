#include <iostream>
#include <numeric>

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    const unsigned d = std::gcd(a, b);
    a /= d;
    b /= d;

    if (a < b && b - a > 1)
        return answer("Dasha");

    if (b < a && a - b > 1)
        return answer("Masha");

    answer("Equal");
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
