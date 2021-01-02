#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    size_t p = n - 2;
    for (unsigned d = 1; k > d; k -= d++)
        --p;

    std::string x(n, 'a');
    x[p] = x[n-k] = 'b';

    answer(x);
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

