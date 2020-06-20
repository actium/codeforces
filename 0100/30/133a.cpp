#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& program)
{
    for (const char c : program) {
        if (c == 'H' || c == 'Q' || c == '9')
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::string program;
    std::cin >> program;

    solve(program);

    return 0;
}

