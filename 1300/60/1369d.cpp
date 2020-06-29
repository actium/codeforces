#include <iostream>

using integer = unsigned long long;

constexpr size_t N = 2e6;
constexpr integer M = 1000000007;

namespace {

    integer x[1+N];

    void initialize()
    {
        for (size_t i = 2; i <= N; ++i)
            x[i] = (2 * x[i-2] + x[i-1] + (i % 3 ? 0 : 4)) % M;
    }

} // anonymous namespace

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    answer(x[n]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
}

int main()
{
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

