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

void solve(size_t n)
{
    std::vector<int> a(n, -1);
    for (size_t i = 1; i < n; i += 2)
        a[i-0] = 3;

    if (n % 2 == 0)
        a[n-1] = 2;

    answer(a);
}

void test_case()
{
    size_t n;
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
