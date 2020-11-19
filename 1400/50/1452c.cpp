#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 0;

    unsigned c1 = 0, c2 = 0;
    for (const char c : s) {
        if (c == '(')
            ++c1;

        if (c == ')' && c1 > 0)
            --c1, ++k;

        if (c == '[')
            ++c2;

        if (c == ']' && c2 > 0)
            --c2, ++k;
    }

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

