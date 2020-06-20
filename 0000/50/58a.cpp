#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& input)
{
    constexpr char m[] = "hello";

    size_t i = 0;
    for (const char c : input) {
        if (c == m[i] && ++i == 5)
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::string input;
    std::cin >> input;

    solve(input);

    return 0;
}

