#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    std::cout << "YES" << '\n';
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(integer n, integer k)
{
    if (n < k)
        return no_answer();

    const integer b = n / k;
    if (n / b == k)
        return answer({ b });

    const integer c = n - (k - 1);
    if (n / c == 1)
        return answer({ c, 1 });

    no_answer();
}

void test_case()
{
    integer n, k;
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
