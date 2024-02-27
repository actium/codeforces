#include <iostream>
#include <string>

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    unsigned f[3] = {};
    for (size_t i = 0; i < n; ++i) {
        f[0] += (s[i] == '1' && t[i] == '0');
        f[1] += (s[i] == '0' && t[i] == '1');
        f[2] += (s[i] == '1' && t[i] == '1');
    }

    if (f[0] + f[2] % 2 > f[1])
        return answer("First");

    if (f[0] + f[2] % 2 + 1 < f[1])
        return answer("Second");

    answer("Draw");
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}