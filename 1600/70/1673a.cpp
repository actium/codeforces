#include <iostream>
#include <string>

void answer(const char* x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::string& s)
{
    unsigned v = 0;
    for (const char c : s) {
        v += 1 + c - 'a';
    }

    if (s.length() % 2 == 0)
        return answer("Alice", v);

    if (s.length() == 1)
        return answer("Bob", v);

    const unsigned d = 1 + std::min(s.front(), s.back()) - 'a';
    answer("Alice", v - 2 * d);
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
