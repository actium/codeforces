#include <iostream>

constexpr unsigned K = 200000;

unsigned t[1+K];

void initialize()
{
    for (unsigned i = 1; i <= K; ++i) {
        for (unsigned x = i; x != 0; x /= 3)
            ++t[i];
    }

    for (unsigned i = 1; i <= K; ++i)
        t[i] += t[i-1];
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned lb, unsigned ub)
{
    answer(t[ub] - t[lb-1] + t[lb] - t[lb-1]);
}

void test_case()
{
    unsigned lb, ub;
    std::cin >> lb >> ub;

    solve(lb, ub);
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
