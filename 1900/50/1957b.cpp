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

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> a(n);
    if (n == 1) {
        a[0] = k;
    } else {
        const unsigned x = 1 << __builtin_clz(1) - __builtin_clz(k);
        a[0] = x - 1;
        a[1] = k - a[0];
    }

    answer(a);
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
