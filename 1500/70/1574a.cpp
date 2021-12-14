#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

std::string generate(size_t k, size_t n)
{
    std::string s;

    for (size_t i = 0; i < k; ++i)
        s += "()";

    for (size_t i = k; i < n; ++i)
        s += '(';

    for (size_t i = k; i < n; ++i)
        s += ')';

    return s;
}

void solve(size_t n)
{
    std::vector<std::string> s;
    for (size_t i = 0; i < n; ++i)
        s.push_back(generate(i, n));

    answer(s);
}

void test_case()
{
    size_t n;
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
