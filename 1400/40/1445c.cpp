#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

std::vector<unsigned> prime_factors(unsigned n)
{
    std::vector<unsigned> pf;
    for (unsigned i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            pf.push_back(i);
            n /= i;
        }
    }
    if (n != 1)
        pf.push_back(n);

    return pf;
}

integer search(integer p, unsigned q, unsigned f)
{
    while (p % q == 0 && p % f == 0)
        p /= f;

    return p;
}

void solve(integer p, unsigned q)
{
    if (p % q != 0)
        return answer(p);

    integer x = 1;
    for (const unsigned f : prime_factors(q))
        x = std::max(x, search(p, q, f));

    answer(x);
}

void test_case()
{
    integer p;
    std::cin >> p;

    unsigned q;
    std::cin >> q;

    solve(p, q);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

