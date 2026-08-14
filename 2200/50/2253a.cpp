#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n + 1);
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
