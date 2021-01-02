#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned m)
{
    const auto c = [](unsigned k) {
        return k * (k - 1ull) / 2;
    };

    const unsigned r = n % m;

    answer((m - r) * c(n / m) + r * c(n / m + 1), c(n - m + 1));
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

