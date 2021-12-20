#include <iostream>
#include <set>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length(), m = b.length();

    std::set<std::string> s;
    for (size_t lb = 0; lb < n; ++lb) {
        for (size_t ub = lb + 1; ub <= n; ++ub)
            s.insert(a.substr(lb, ub - lb));
    }

    size_t k = n + m;
    for (const std::string& x : s) {
        if (b.find(x) != std::string::npos)
            k = std::min(k, n + m - 2 * x.length());
    }

    answer(k);
}

void test_case()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
