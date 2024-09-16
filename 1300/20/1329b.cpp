#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned d, unsigned m)
{
    unsigned long long x = 0, dx = 1, k = 0, dk = 1;
    while (x + dx <= d) {
        k = (k + dx * dk) % m;
        dk = dk * (dx + 1) % m;

        x += dx;
        dx *= 2;
    }

    k += (d - x) * dk % m;

    answer(k % m);
}

void test_case()
{
    unsigned d, m;
    std::cin >> d >> m;

    solve(d, m);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
