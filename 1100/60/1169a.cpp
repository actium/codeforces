#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned a, unsigned x, unsigned b, unsigned y)
{
    --a, --x, --b, --y;

    while (a != x && b != y && a != b) {
        a = (n + a + 1) % n;
        b = (n + b - 1) % n;
    }

    answer(a == b);
}

int main()
{
    unsigned n, a, x, b, y;
    std::cin >> n >> a >> x >> b >> y;

    solve(n, a, x, b, y);

    return 0;
}

