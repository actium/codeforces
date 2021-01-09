#include <iostream>
#include <string>

constexpr unsigned M = 998244353;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t ps = 1;
    while (s[ps] == s[ps-1])
        ++ps;

    size_t ss = 1;
    while (s[n-1-ss] == s[n-ss])
        ++ss;

    unsigned k = 1 + ps + ss;
    if (s.front() == s.back())
        k += 1ull * ps * ss % M;

    answer(k % M);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

