#include <algorithm>
#include <array>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::array<unsigned, 10>& c)
{
    const size_t x = std::min_element(c.begin(), c.end()) - c.begin();
    if (x == 9) {
        answer('1' + std::string(c[9] + 1, '0'));
    } else {
        answer(std::string(c[x] + 1, '1' + x));
    }
}

void test_case()
{
    std::array<unsigned, 10> c;
    for (size_t i = 9; i < 19; ++i)
        std::cin >> c[i % 10];

    solve(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
