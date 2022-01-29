#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b, unsigned c, unsigned d)
{
    const auto check = [n](int x) {
        return x - 1 < n;
    };

    integer k = 0;
    for (unsigned x = 1; x <= n; ++x) {
        const unsigned y = x + b - c;
        if (check(y) && check(x + a - d) && check(y + a - d))
            k += n;
    }

    answer(k);
}

int main()
{
    unsigned n, a, b, c, d;
    std::cin >> n >> a >> b >> c >> d;

    solve(n, a, b, c, d);

    return 0;
}
