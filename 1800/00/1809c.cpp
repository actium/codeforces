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

void solve(size_t n, size_t k)
{
    std::vector<int> a(n, 1);

    size_t m = n * (n + 1) / 2;
    for (size_t i = n; i > 0; --i) {
        if (m - i >= k) {
            a[i-1] = -a[i-1];
            m -= i;
        }
    }

    int s = abs(a[0]);
    for (size_t i = 1; i < n; ++i) {
        if ((a[i] < 0) != (a[i-1] < 0))
            a[i] *= s + 1;

        s += abs(a[i]);
    }

    answer(a);
}

void test_case()
{
    size_t n, k;
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
