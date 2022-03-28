#include <iostream>
#include <string>

void answer(const std::pair<unsigned, unsigned>& x)
{
    std::cout << x.first << ' ' << x.second << '\n';
}

bool palindrome(const std::string& s, size_t l, size_t r)
{
    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

std::pair<unsigned, unsigned> solve(const std::string& s, size_t lb, size_t ub)
{
    const unsigned d = ub - lb;
    if (d > 1 && s[lb] == '(') {
        std::pair<unsigned, unsigned> r = solve(s, lb + 2, ub);
        ++r.first;
        return r;
    }

    const size_t x = s.find(')', lb + 1);
    if (x != std::string::npos) {
        std::pair<unsigned, unsigned> r = solve(s, x + 1, ub);
        ++r.first;
        return r;
    }

    return { 0, d };
}

void solve(const std::string& s)
{
    answer(solve(s, 0, s.length()));
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
