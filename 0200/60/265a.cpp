#include <iostream>
#include <string>

void answer(size_t i)
{
    std::cout << 1 + i << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    size_t i = 0;
    for (const char c : t) {
        if (c == s[i])
            ++i;
    }

    answer(i);
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

