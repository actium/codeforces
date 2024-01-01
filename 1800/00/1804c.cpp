#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned x, unsigned p)
{
    x = (n - x) % n;

    for (unsigned f = 1, s = 0; f <= std::min(2 * n, p); ++f) {
        s = (s + f) % n;
        if (s == x)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    unsigned n, x, p;
    std::cin >> n >> x >> p;

    solve(n, x, p);
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
