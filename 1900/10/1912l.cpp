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

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned f[2] = {}; // L, O
    for (const char c : s)
        ++f[c == 'O'];

    unsigned i = 0, p[2] = {};
    do {
        ++p[s[i++] == 'O'];
    } while (i < n && (p[0] == f[0] - p[0] || p[1] == f[1] - p[1]));

    i < n ? answer(i) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
