#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    if (a == 1)
        return answer((n - 1) % b == 0);

    for (unsigned long long d = 1; d <= n; d *= a) {
        if (d % b == n % b)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0) {
        test_case();
    }

    return 0;
}
