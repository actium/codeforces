#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t count = 0;
    for (const char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || isdigit(c) && c % 2 != 0)
            ++count;
    }

    answer(count);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

