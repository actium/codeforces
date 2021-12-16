#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] == '0' && s[i] == '1')
            ++k;
    }

    answer(std::min(k, 2u));
}

void test_case()
{
    std::string s;
    std::cin >> s;

    s.push_back('1');
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
