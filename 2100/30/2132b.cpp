#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(integer n)
{
    std::vector<integer> s;
    for (integer k = 10; k < n; k *= 10) {
        if (n % (k + 1) == 0)
            s.push_back(n / (k + 1));
    }

    std::reverse(s.begin(), s.end());

    answer(s);
}

void test_case()
{
    integer n;
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
