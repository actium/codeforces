#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string (& s)[2])
{
    unsigned x = 0;
    for (const std::string& t : s) {
        for (const char c : t)
            x ^= (c == 'f');
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s[2];
    std::cin >> s[0] >> s[1];

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
