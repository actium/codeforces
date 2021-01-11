#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    char x = 'a';
    for (size_t i = 0; i < n && x <= 'z'; ++i) {
        if (s[i] <= x)
            s[i] = x++;
    }

    if (x > 'z')
        return answer(s);

    no_answer();
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

