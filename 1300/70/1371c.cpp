#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(integer a, integer b, integer n, integer m)
{
    if (a + b < n + m)
        return answer(false);

    if (a > b) {
        const integer k = std::min(b, m);
        b -= k, m -= k;
    } else {
        const integer k = std::min(a, m);
        a -= k, m -= k;
    }

    answer(m == 0);
}

void test_case()
{
    integer a, b, n, m;
    std::cin >> a >> b >> n >> m;

    solve(a, b, n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

