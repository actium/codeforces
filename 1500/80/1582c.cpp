#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

std::pair<bool, unsigned> solve(const std::string& s, size_t lb, size_t ub, char c)
{
    if (lb >= ub)
        return { true, 0 };

    if (s[lb] == s[ub])
        return solve(s, lb+1, ub-1, c);

    if (s[lb] == c) {
        const auto r = solve(s, lb+1, ub, c);
        return { r.first, r.second + 1 };
    }
    if (s[ub] == c) {
        const auto r = solve(s, lb, ub-1, c);
        return { r.first, r.second + 1 };
    }

    return { false, 0 };
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t k = 0;
    while (k < n / 2 && s[k] == s[n-1-k])
        ++k;

    const auto r1 = solve(s, k, n-1-k, s[k]), r2 = solve(s, k, n-1-k, s[n-1-k]);
    if (r1.first && r2.first)
        return answer(std::min(r1.second, r2.second));

    if (r1.first)
        return answer(r1.second);

    if (r2.first)
        return answer(r2.second);

    no_answer();
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
