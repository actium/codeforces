#include <iostream>
#include <string>

unsigned digit(char c)
{
    return c - '0';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (digit(c) % 2 == 1)
            t.push_back(c);
    }

    if (t.length() < 2)
        answer(-1);
    else
        answer(t.substr(0, 2));
}

void test_case()
{
    size_t n;
    std::cin >> n;

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

