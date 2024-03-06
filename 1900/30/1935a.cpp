#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned n)
{
    const std::string t = std::string(s.rbegin(), s.rend()) + s;

    answer(std::min(s, t));
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s, n);
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
