#include <iostream>
#include <string>

void answer(int v)
{
    std::cout << v << '\n';
}

size_t index(char c)
{
    return c - 'A';
}

void solve(const std::string& s)
{
    if (s.length() % 2 != 0)
        return answer(-1);

    int x = 0, y = 0;
    for (const char c : s) {
        x += (c == 'R') - (c == 'L');
        y += (c == 'U') - (c == 'D');
    }

    answer((abs(x) + abs(y)) / 2);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

