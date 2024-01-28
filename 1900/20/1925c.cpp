#include <iostream>
#include <string>

void answer(bool v, const std::string& w)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
    std::cout << w << '\n';
}

void solve(size_t n, size_t k, const std::string& s)
{
    std::string p;

    unsigned t = (1 << k) - 1, q = 0;
    for (const char c : s) {
        t &= ~(1 << c - 'a');
        if (t == 0) {
            t = (1 << k) - 1;
            ++q;
            p.push_back(c);
        }
    }

    if (q >= n)
        return answer(true, "");

    p.resize(n, 'a' + __builtin_ctz(t));
    answer(false, p);
}

void test_case()
{
    size_t n, k, m;
    std::cin >> n >> k >> m;

    std::string s;
    std::cin >> s;

    solve(n, k, s);
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
