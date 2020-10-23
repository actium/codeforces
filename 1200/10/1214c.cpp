#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (c == '(' || t.empty() || t.back() == ')')
            t.push_back(c);
        else
            t.pop_back();
    }

    answer(t.empty() || t == ")(");
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

