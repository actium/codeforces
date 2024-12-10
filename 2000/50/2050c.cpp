#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    unsigned r = 0;
    for (const char c : s)
        r += c - '0';

    bool v[9] = {};
    v[r % 9] = true;
    for (const char c : s) {
        const unsigned d = c - '0';
        if (d != 2 && d != 3)
            continue;

        bool nv[9] = {};
        for (size_t i = 0; i < 9; ++i) {
            if (v[i])
                nv[(i + d * d - d) % 9] = true;
        }

        for (size_t i = 0; i < 9; ++i)
            v[i] = v[i] || nv[i];
    }

    answer(v[0]);
}

void test_case()
{
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
