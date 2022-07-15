#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 1;

    unsigned v = 0;
    for (const char c : s) {
        const unsigned x = c - 'a';

        v |= 1 << x;
        if (__builtin_popcount(v) < 4)
            continue;

        v = 1 << x;
        ++k;
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
