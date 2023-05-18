#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const char t[] = "codeforces";

    unsigned k = 0;
    for (size_t i = 0; i < 10; ++i)
        k += (s[i] != t[i]);

    answer(k);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
