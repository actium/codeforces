#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length(), m = t.length();

    size_t si1 = 0, ti1 = 0;
    while (si1 < n && ti1 < m)
        si1 += (t[ti1++] == s[si1]);

    size_t si2 = n-1, ti2 = m-1;
    while (~si2 && ~ti2)
        si2 -= (t[ti2--] == s[si2]);

    answer(--ti1 < ++ti2 ? ti2 - ti1 : 0);
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
