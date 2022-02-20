#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto count = [&s](char a, char b) {
        unsigned k = 0;
        for (const char c : s) {
            if (c == a) {
                ++k;
                std::swap(a, b);
            }
        }
        return k - (a != b ? k % 2 : 0);
    };

    unsigned k = 2;
    for (char a = '0'; a <= '9'; ++a) {
        for (char b = '0'; b <= '9'; ++b)
            k = std::max(k, count(a, b));
    }

    answer(n - k);
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
