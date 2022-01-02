#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 10;
    for (unsigned i = 1, v1 = 0, v2 = 0; i <= 10; ++i) {
        if (i % 2 == 1)
            v1 += (s[i-1] != '0');
        else
            v2 += (s[i-1] == '1');

        if (v1 > v2 + (11 - i) / 2)
            k = std::min(k, i);
    }
    for (unsigned i = 1, v1 = 0, v2 = 0; i <= 10; ++i) {
        if (i % 2 == 1)
            v1 += (s[i-1] == '1');
        else
            v2 += (s[i-1] != '0');

        if (v2 > v1 + (10 - i) / 2)
            k = std::min(k, i);
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
