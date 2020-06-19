#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t m = 0, k = 0;

    bool a = false;
    for (const char c : s) {
        if (c == 'A') {
            a = true;
            k = 0;
        } else if (a) {
            ++k;
            m = std::max(m, k);
        }
    }

    answer(m);
}

void test_case()
{
    size_t k;
    std::cin >> k;

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

