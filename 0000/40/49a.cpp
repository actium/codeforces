#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& q)
{
    char last_c = ' ';
    for (const char c : q) {
        if (isalpha(c))
            last_c = tolower(c);
    }

    answer(last_c == 'a' || last_c == 'e' || last_c == 'i' || last_c == 'o' || last_c == 'u' || last_c == 'y');
}

int main()
{
    std::string q;
    std::getline(std::cin, q);

    solve(q);

    return 0;
}

