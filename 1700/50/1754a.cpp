#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& q)
{
    int b = 0;
    for (const char c : q) {
        b += (c == 'Q' ? 1 : -1);
        if (b < 0)
            b = 0;
    }

    answer(b == 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string q;
    std::cin >> q;

    solve(q);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
