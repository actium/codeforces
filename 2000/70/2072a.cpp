#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k, unsigned p)
{
    if (n * p >= k)
        return answer((k + p - 1) / p);

    no_answer();
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    int k;
    std::cin >> k;

    unsigned p;
    std::cin >> p;

    solve(n, std::abs(k), p);
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
