#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; i += 2) {
        if (++s[i] != 'b')
            s[i] = 'a';
    }
    for (size_t i = 1; i < n; i += 2) {
        if (--s[i] != 'y')
            s[i] = 'z';
    }

    answer(s);
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

