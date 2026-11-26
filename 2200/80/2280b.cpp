#include <iostream>

unsigned query(unsigned lb, unsigned ub)
{
    std::cout << '?' << ' ' << lb << ' ' << ub << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << '!' << ' ' << s[v] << std::endl;
}

void solve(unsigned n)
{
    const unsigned k = query(1, n);
    answer(k != 0 && k != n && query(1, k) != k);
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

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
