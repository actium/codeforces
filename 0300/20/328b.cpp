#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& t, const std::string& s)
{
    unsigned f[10] = {};
    for (const char c : s)
        ++f[c-'0'];

    const auto check = [&] {
        for (char c : t) {
            if ((c == '2' || c == '5') && f[c-'0'] == 0)
                c ^= '2' ^ '5';
            if ((c == '6' || c == '9') && f[c-'0'] == 0)
                c ^= '6' ^ '9';

            if (f[c-'0'] == 0)
                return false;

            --f[c-'0'];
        }
        return true;
    };

    unsigned k = 0;
    while (check())
        ++k;

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string t, s;
    std::cin >> t >> s;

    solve(t, s);

    return 0;
}
