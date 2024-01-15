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

void solve(size_t n)
{
    std::vector<unsigned> a(n);
    for (size_t i = 1; i < n; i += 2) {
        a[i-1] = i;
        a[i] = i+1;
    }

    unsigned x[2] = {};
    for (size_t i = 0; i < n; ++i)
        x[i % 2] ^= a[i];

    if (x[0] != x[1] && n % 2 == 1) {
        a[n-1] = x[0] ^ x[1] ^ 1<<25;
        x[1] ^= a[n-1];
    }
    if (x[0] != x[1]) {
        a[0] ^= x[0] ^ 1<<20;
        a[1] ^= x[1] ^ 1<<20;
    }

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
