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

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    unsigned f[3] = {};
    for (size_t i = 0; i < n; ++i) {
        f[0] += (s[i] == '1');
        f[1] += (t[i] == '1');
        f[2] += (s[i] != t[i]);
    }

    if (f[0] == 0)
        return f[1] == 0 ? answer(0) : no_answer();

    const unsigned u = n - (f[0] - 1);
    if (f[0] == f[1] && u == f[1])
        return answer(std::min<unsigned>(f[2], n - f[2]));

    if (f[0] == f[1])
        return answer(f[2]);

    if (u == f[1])
        return answer(n - f[2]);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
