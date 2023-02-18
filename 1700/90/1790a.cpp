#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& n)
{
    constexpr const char* p = "314159265358979323846264338327";

    answer(std::mismatch(n.begin(), n.end(), p).first - n.begin());
}

void test_case()
{
    std::string n;
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
