#include <iostream>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned a = 0, b = 1;
    while (n-- != 0) {
        const unsigned c = (a + b + 2) % M;
        a = b;
        b = c;
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
