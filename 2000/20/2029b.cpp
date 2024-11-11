#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& r)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    for (const char c : r) {
        if (f[0] == 0 || f[1] == 0)
            return answer(false);

        --f[(c-'0')^1];
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s, r;
    std::cin >> s >> r;

    solve(s, r);
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
