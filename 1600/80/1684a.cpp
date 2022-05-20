#include <algorithm>
#include <iostream>
#include <string>

void answer(char x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    const std::string s = std::to_string(n);

    answer(s.length() == 2 ? s.back() : *std::min_element(s.cbegin(), s.cend()));
}

void test_case()
{
    unsigned n;
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
