#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    if (n % 2 == 0)
        return no_answer();

    std::vector<unsigned> p(n);
    for (unsigned i = 1; 2 * i < n; ++i) {
        p[i-1] = n - i + 1;
        p[n-i] = n / 2 - i + 2;
    }
    p[n/2] = 1;

    answer(p);
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
