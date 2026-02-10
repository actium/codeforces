#include <iostream>
#include <string>

void answer(size_t x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (s.find(")((") != std::string::npos)
        return answer(n - 2);

    unsigned b = 0, r = 0, u = 0;
    for (const char c : s) {
        b += (c == '(' ? 1 : -1);
        r += (b == 0);
        u = std::max(u, b);
    }

    if (2 * u == n || 2 * u == n - 2 && r < 3)
        return no_answer();

    answer(n - 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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
