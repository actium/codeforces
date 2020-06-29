#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& b)
{
    const size_t n = b.length();

    std::string a;
    a.push_back(b[0]);
    for (size_t i = 1; i < n-1; i += 2)
        a.push_back(b[i]);

    a.push_back(b.back());
    answer(a);
}

void test_case()
{
    std::string b;
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

