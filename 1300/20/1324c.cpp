#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    s.push_back('R');

    const size_t n = s.length();

    size_t l = 0, d = 0;
    for (size_t r = 0; r < n; ++r) {
        if (s[r] == 'R') {
            d = std::max(d, r - l + 1);
            l = r + 1;
        }
    }

    answer(d);
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

