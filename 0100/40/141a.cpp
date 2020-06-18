#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& guest, const std::string& host, const std::string& letters)
{
    if (guest.length() + host.length() != letters.length())
        return answer(false);

    int balance[26] = {};

    for (const char c : guest)
        --balance[c - 'A'];

    for (const char c : host)
        --balance[c - 'A'];

    for (const char c : letters)
        ++balance[c - 'A'];

    for (size_t i = 0; i < 26; ++i) {
        if (balance[i] != 0)
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::string guest, host, letters;
    std::cin >> guest >> host >> letters;

    solve(guest, host, letters);

    return 0;
}

