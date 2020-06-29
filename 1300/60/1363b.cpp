#include <algorithm>
#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t x = ~0;
    for (size_t i = 0; i < n; ++i) {
        const size_t c1 = std::count(s.begin(), s.begin() + i, '0') + std::count(s.begin() + i, s.end(), '1');
        const size_t c2 = std::count(s.begin(), s.begin() + i, '1') + std::count(s.begin() + i, s.end(), '0');
        x = std::min({ x, c1, c2 });
    }

    answer(x);
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

