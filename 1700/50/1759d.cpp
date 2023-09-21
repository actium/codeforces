#include <iostream>
#include <vector>

using integer = unsigned long long;

std::pair<unsigned, integer> evaluate(unsigned n, unsigned k) {
    std::pair<unsigned, integer> v = { 0, 1ull * n * k };

    for (integer x = v.second; x % 10 == 0; x /= 10)
        ++v.first;

    return v;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    std::pair<unsigned, integer> v = evaluate(n, m);

    integer k = 1;
    {
        unsigned x = n;
        while (x % 10 == 0)
            x /= 10;

        if (x % 2 == 0) {
            for (unsigned q = x; q % 2 == 0 && k * 5 < m; q /= 2)
                k *= 5;
        }
        if (x % 10 == 5) {
            for (unsigned q = x; q % 10 == 5 && k * 2 < m; q /= 5)
                k *= 2;
        }
    }

    while (k * 10 < m)
        k *= 10;

    for (unsigned i = 1; i * k < m; ++i)
        v = std::max(v, evaluate(n, i * k));

    answer(v.second);
}

void solve_slow(unsigned n, unsigned m)
{
    std::pair<unsigned, integer> v = evaluate(n, m);
    for (unsigned k = 1; k <= m; ++k)
        v = std::max(v, evaluate(n, k));

    answer(v.second);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
    // solve_slow(n, m);
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
