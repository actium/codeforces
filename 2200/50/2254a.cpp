#include <algorithm>
#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned (& s)[3])
{
    std::sort(std::begin(s), std::end(s));

    answer(std::min(s[2] - s[1], s[1] - s[0]));
}

void test_case()
{
    unsigned s[3];
    std::cin >> s[0] >> s[1] >> s[2];

    solve(s);
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
