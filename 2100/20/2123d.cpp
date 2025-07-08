#include <iostream>
#include <string>

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    unsigned q = 0;
    for (const char c : s)
        q += c - '0';

    answer(q <= k || 2 * k > s.size() ? "Alice" : "Bob");
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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
