#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NET", "DA" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    size_t f[2] = {};
    for (const char c : s) {
        ++f[c - '0'];
    }

    const size_t k = std::min(f[0], f[1]); 
    answer(k % 2 == 1);
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

