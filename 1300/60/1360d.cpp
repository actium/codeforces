#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n <= k)
        return answer(1);

    unsigned m = n;
    for (unsigned i = 2; i * i <= n && i <= k; ++i) {
        if (n % i != 0)
            continue;

        m = std::min(m, n / i);

        if (n / i <= k)
            m = std::min(m, i);
    }

    answer(m);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

