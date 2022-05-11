#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned q = 0, k = 0;

    char x = ' ';
    for (const char c : s) {
        if (c != x && q % 2 != 0) {
            ++k;
            q = 1;
        }
        ++q;
        x = c;
    }

    answer(k);
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
