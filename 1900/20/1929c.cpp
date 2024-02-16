#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned k, unsigned x, unsigned a)
{
    using integer = unsigned long long;

    integer s = 1;
    for (unsigned i = 0; i < x; ++i) {
        integer b = (s + k - 2) / (k - 1);
        if (b * k <= s + b)
            ++b;

        s += b;

        if (s > a)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    unsigned k, x, a;
    std::cin >> k >> x >> a;

    solve(k, x, a);
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
