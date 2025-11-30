#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, unsigned x, unsigned y)
{
    const size_t n = s.length();

    if (x > n || y > n)
        return answer(false);

    unsigned k = 0;
    for (const char c : s)
        k += (c == '8');

    answer(x + y <= n + k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int x, y;
    std::cin >> x >> y;

    std::string s;
    std::cin >> s;

    solve(s, abs(x), abs(y));
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
