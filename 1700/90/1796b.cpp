#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length(), m = b.length();

    if (a[0] == b[0])
        return answer(a.substr(0, 1) + "*");

    if (a[n-1] == b[m-1])
        return answer("*" + a.substr(n-1, 1));

    for (size_t i = 1; i < n; ++i) {
        const std::string p = a.substr(i - 1, 2);
        if (b.find(p) != std::string::npos)
            return answer("*" + p + "*");
    }

    no_answer();
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
