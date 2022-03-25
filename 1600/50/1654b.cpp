#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t p[26] = {}, x = n;
    for (size_t i = n; i-- > 0; ) {
        const size_t j = s[i] - 'a';
        if (p[j] == 0)
            x = i;

        p[j] = i;
    }

    answer(s.substr(x));
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
