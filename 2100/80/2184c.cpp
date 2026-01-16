#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k)
{
    unsigned lb = n, ub = n, c = 0;
    while (lb > k) {
        lb = (lb + 0) / 2;
        ub = (ub + 1) / 2;
        ++c;
    }

    if (lb <= k && k <= ub)
        return answer(c);

    no_answer();
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

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
