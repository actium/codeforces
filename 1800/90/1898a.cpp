#include <iostream>
#include <string>

void solve(const std::string& s, size_t k)
{
    unsigned q = 0;
    for (const char c : s)
        q += (c == 'B');

    if (q == k) {
        std::cout << 0 << '\n';
        return;
    }

    std::cout << 1 << '\n';
    if (q < k) {
        size_t x = 0;
        while (q < k)
            q += (s[x++] == 'A');

        std::cout << x << ' ' << 'B' << '\n';
    } else {
        size_t x = 0;
        while (q > k)
            q -= (s[x++] == 'B');

        std::cout << x << ' ' << 'A' << '\n';
    }
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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
