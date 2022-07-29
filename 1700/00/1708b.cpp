#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(size_t n, unsigned l, unsigned r)
{
    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned d = 1 + i;
        a[i] = r / d * d;
        if (a[i] < l)
            return no_answer();
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned l, r;
    std::cin >> l >> r;

    solve(n, l, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
