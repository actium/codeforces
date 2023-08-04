#include <iostream>

unsigned f[28];

void initialize()
{
    unsigned a = 0, b = 1;

    for (unsigned i = 0; i < 28; ++i) {
        f[i] = a;

        const unsigned c = a + b;
        a = b;
        b = c;
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (k > 28)
        return answer(0);

    const unsigned a = f[k-2], b = f[k-1];

    unsigned q = 0;
    for (unsigned x = 0; x <= n; x += a) {
        const unsigned d = n - x;
        if (d % b == 0 && d * a >= x * b)
            ++q;
    }

    answer(q);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
