#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const size_t x = n % 2;

    unsigned k = 0;
    for (size_t i = x^1; i < n; i += 2) {
        const char c = s[i] - '0';
        if (c % 2 == x)
            ++k;
    }

    answer(k > 0 ? 2 - x : 1 + x);
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

