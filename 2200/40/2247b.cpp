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

void solve(size_t n, size_t k, unsigned m)
{
    if (k > m)
        return no_answer();

    std::vector<unsigned> a(n, 1);
    a[k-1] = m - k + 1;

    answer(a);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    unsigned m;
    std::cin >> m;

    solve(n, k, m);
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
