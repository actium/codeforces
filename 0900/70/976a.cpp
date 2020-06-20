#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    if (s.length() == 1)
        return answer(s);

    std::string t = "1";
    for (const char c : s) {
        if (c == '0')
            t.push_back('0');
    }

    answer(t);
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

