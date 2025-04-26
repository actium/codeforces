#include <iostream>
#include <string>
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
    const size_t n = s.length() + 1;

    std::vector<unsigned> p(n);
    {
        unsigned lb = 1, ub = n;
        for (size_t i = 1; i < n; ++i)
            p[n-i] = (s[n-1-i] == '<' ? lb++ : ub--);

        p[0] = lb;
    }
    answer(p);
}

void test_case()
{
    unsigned n;
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
