#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned delta(unsigned a, unsigned b)
{
    return std::max(a, b) - std::min(a, b);
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (s[i] - '0');

    unsigned x = ~0u;
    for (size_t i = 0; i <= n; ++i) {
        const unsigned lv = i - p[i], rv = p[n] - p[i];
        if (2 * lv < i || 2 * rv < n - i)
            continue;

        if (x == ~0u || delta(n, 2 * i) < delta(n, 2 * x))
            x = i;
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
