#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& a)
{
    std::sort(a.begin(), a.end());

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

