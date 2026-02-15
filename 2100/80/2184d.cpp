#include <iostream>

unsigned C[30][30];

void initialize()
{
    for (unsigned i = 0; i < 30; ++i) {
        C[i][0] = 1;

        for (unsigned j = 1; j <= i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    const unsigned d = __builtin_ctz(n);

    unsigned c = (d >= k);
    for (unsigned w = 1; w <= d; ++w) {
        for (unsigned i = 0; i < w; ++i) {
            if (w + i > k)
                c += C[w-1][i];
        }
    }

    answer(c);
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
