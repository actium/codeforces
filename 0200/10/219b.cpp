#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer p, integer d)
{
    for (integer b = 1; b < p; b *= 10) {
        const integer r = (p / b) % 10 + 10, q = (r - 9) % 10 * b;
        if (q <= d) {
            p -= q;
            d -= q;
        }
    }

    answer(p);
}

int main()
{
    integer p, d;
    std::cin >> p >> d;

    solve(p, d);

    return 0;
}
