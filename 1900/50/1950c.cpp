#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const unsigned h = (s[0] - '0') * 10 + (s[1] - '0');

    if (h == 0) {
        s[0] = '1';
        s[1] = '2';
    }
    if (h > 12) {
        s[0] = '0' + (h - 12) / 10;
        s[1] = '0' + (h - 12) % 10;
    }

    answer(s + (h < 12 ? " AM" : " PM"));
}

void test_case()
{
    std::string s;
    std::cin >> s;

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
