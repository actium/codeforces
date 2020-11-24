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

std::vector<integer> factorize(integer n, integer b)
{
    std::vector<integer> f;
    while (n % b == 0) {
        f.push_back(b);
        n /= b;
    }

    if (f.empty())
        f.push_back(n);
    else
        f.back() *= n;

    return f;
}

void solve(integer n)
{
    std::vector<integer> b = { n };
    for (integer x = 2; x * x <= n; ++x) {
        auto c = factorize(n, x);
        if (c.size() > b.size())
            b.swap(c);
    }

    answer(b);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

