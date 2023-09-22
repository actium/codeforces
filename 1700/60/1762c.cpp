#include <iostream>
#include <string>

constexpr unsigned M = 998244353;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned long long p = 1, q = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == s[i-1])
            p = p * 2 % M;
        else
            p = 1;

        q += p;
    }

    answer(q % M);
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
