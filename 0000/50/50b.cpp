#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned f[256] = {};
    for (const char c : s)
        ++f[c];

    const auto count = [&](char lb, char ub) {
        integer k = 0;
        for (char c = lb; c <= ub; ++c)
            k += 1ull * f[c] * f[c];

        return k;
    };

    answer(count('0', '9') + count('a', 'z'));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
