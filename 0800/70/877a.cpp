#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 0;
    for (const std::string x : { "Danil", "Olya", "Slava", "Ann", "Nikita" }) {
        for (size_t i = s.find(x); i != std::string::npos; i = s.find(x, i + 1))
            ++k;
    }

    answer(k == 1);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

