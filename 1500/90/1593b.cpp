#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    const std::string s = std::to_string(n);

    size_t k = s.length();
    for (const char* const c : { "00", "25", "50", "75" }) {
        const auto x = s.rfind(c[1]);
        if (x == 0 || x == std::string::npos)
            continue;

        const auto y = s.rfind(c[0], x - 1);
        if (y != std::string::npos)
            k = std::min(k, s.length() - y - 2);
    }

    answer(k);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
