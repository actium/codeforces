#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> pl(1+n), pr(1+n);
    pr[0] = (s[0] == 'R');
    for (size_t i = 1; i <= n; ++i) {
        if (s[i-1] == 'L')
            pl[i] = pr[i-1] + 1;
        else
            pr[i] = pl[i-1] + 1;
    }

    std::vector<unsigned> sl(1+n), sr(1+n);
    sl[n] = (s[n-1] == 'L');
    for (size_t i = n-1; ~i != 0; --i) {
        if (s[i] == 'L')
            sl[i] = sr[i+1] + 1;
        else
            sr[i] = sl[i+1] + 1;
    }

    std::vector<unsigned> c(1+n);
    for (size_t i = 0; i <= n; ++i)
        c[i] = 1 + pl[i] + sr[i];

    answer(c);
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
