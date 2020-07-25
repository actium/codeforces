#include <iostream>
#include <string>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    unsigned f[2] = {};
    for (const char c : s) {
        if (c == '4')
            ++f[0];

        if (c == '7')
            ++f[1];
    }

    if (f[0] == 0 && f[1] == 0)
        return no_answer();

    answer(f[0] >= f[1] ? "4" : "7");
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

