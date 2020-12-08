#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    size_t i = s.find_first_not_of("a");
    if (i != std::string::npos) {
        for (const size_t n = s.length(); i < n && s[i] != 'a'; ++i)
            --s[i];
    } else {
        s.back() = 'z';
    }

    answer(s);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

