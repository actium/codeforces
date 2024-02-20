#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    const auto search = [](unsigned x) {
        unsigned d = 0;
        while (x != 0) {
            d = std::max(d, x % 10);
            x /= 10;
        }
        return d;
    };

    const unsigned d = std::max(search(a), search(b)) + 1;

    unsigned k = 0;
    for (unsigned c = 0; a + b + c != 0; a /= 10, b /= 10, c /= d) {
        c += a % 10;
        c += b % 10;
        ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
