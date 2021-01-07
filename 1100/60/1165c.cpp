#include <iostream>
#include <string>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (t.length() % 2 == 0 || c != t.back())
            t.push_back(c);
    }

    if (t.length() % 2 == 1)
        t.pop_back();

    answer(s.length() - t.length(), t);
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

