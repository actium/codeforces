#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
#if false
    size_t yes = 0, no = 0;

    char last = '\0';
    for (const char c : s) {
        if (c == 'F' && last == 'S')
            ++yes;

        if (c == 'S' && last == 'F')
            ++no;

        last = c;
    }

    answer(yes > no);
#else
    answer(s.front() == 'S' && s.back() == 'F');
#endif
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

