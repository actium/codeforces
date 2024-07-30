#include <iostream>
#include <vector>

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned x, unsigned y)
{
    std::vector<int> a(n, 1);
    for (size_t i = y; i > 1; i -= 2)
        a[i-2] = -1;
    for (size_t i = x; i < n; i += 2)
        a[i] = -1;

    answer(a);
}

void test_case()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);
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
