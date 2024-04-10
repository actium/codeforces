#include <iostream>

constexpr unsigned K = 10000000;

unsigned spf[1 + K];

void initialize()
{
    for (unsigned i = 2; i <= K; i += 2)
        spf[i] = 2;

    unsigned x = 3;
    for (unsigned i = 9; i <= K; i += 4 * ++x, ++x) {
        if (spf[x] != 0)
            continue;

        spf[x] = x;

        for (unsigned j = i; j <= K; j += 2 * x) {
            if (spf[j] == 0)
                spf[j] = x;
        }
    }

    while (x <= K) {
        if (spf[x] == 0)
            spf[x] = x;

        x += 2;
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void infinity()
{
    std::cout << -1 << '\n';
}

void solve(unsigned x, unsigned y)
{
    if (y - x == 1)
        return infinity();

    unsigned v = ~0u;
    for (unsigned d = y - x; d != 1; d /= spf[d])
        v = std::min(v, spf[d] - (x - 1) % spf[d] - 1);

    answer(v);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
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
