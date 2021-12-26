#include <iostream>
#include <string>

void answer(unsigned v)
{
    constexpr const char* s[3] = { "DRAW", "BOB", "ALICE" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 0;
    for (const char c : s)
        k += (c == '0');

    if (k == 0)
        return answer(0);

    answer(k % 2 + (k != 1));
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
