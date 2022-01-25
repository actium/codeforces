#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k, unsigned a, unsigned b)
{
    if (k == 1)
        return answer((n - 1ull) * a);

    integer c = 0;
    while (n != 1) {
        const unsigned r = n % k, q = n / k;
        if (r != 0) {
            const integer d = std::min(n - 1, r);
            c += d * a;
            n -= d;
        } else {
            c += std::min<integer>(b, 1ull * (n - q) * a);
            n = q;
        }
    }

    answer(c);
}

int main()
{
    unsigned n, k, a, b;
    std::cin >> n >> k >> a >> b;

    solve(n, k, a, b);

    return 0;
}
