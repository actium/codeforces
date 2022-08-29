#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, integer k, integer b, integer s)
{
    const integer q = k * b, r = n * (k - 1);
    if (s < q || s > q + r)
        return no_answer();

    std::vector<integer> a = { s };
    while (a[0] / k > b) {
        a[0] -= k - 1;
        a.push_back(k - 1);
    }
    a.resize(n);

    answer(a);
}

void test_case()
{
    integer n, k, b, s;
    std::cin >> n >> k >> b >> s;

    solve(n, k, b, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
