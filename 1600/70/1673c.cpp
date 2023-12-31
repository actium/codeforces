#include <iostream>

constexpr unsigned M = 1000000007;

unsigned dp[1 + 40000];

void initialize()
{
    dp[0] = 1;

    const auto process = [](unsigned x) {
        for (unsigned i = x; i <= 40000; ++i)
            dp[i] = (dp[i] + dp[i-x]) % M;
    };

    for (unsigned i = 1; i < 10; ++i) {
        process(i);
        process(11 * i);

        for (unsigned j = 0; j < 10; ++j) {
            process(101 * i + 10 * j);
            process(1001 * i + 110 * j);

            for (unsigned k = 0; k < 10; ++k)
                process(10001 * i + 1010 * j + 100 * k);
        }
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    answer(dp[n]);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
