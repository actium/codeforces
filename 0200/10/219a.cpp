#include <iostream>
#include <string>

std::string k_string(const size_t f[26], unsigned k)
{
    std::string pattern;
    for (size_t i = 0; i < 26; ++i) {
        if (f[i] == 0)
            continue;

        if (f[i] % k != 0)
            return "-1";

        pattern += std::string(f[i] / k, 'a' + i);
    }

    std::string s;
    while (k-- > 0)
        s += pattern;

    return s;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& letters, unsigned k)
{
    size_t f[26] = { 0 };
    for (const char c : letters)
        ++f[c - 'a'];

    answer(k_string(f, k));
}

int main()
{
    unsigned k;
    std::cin >> k;

    std::string letters;
    std::cin >> letters;

    solve(letters, k);

    return 0;
}

