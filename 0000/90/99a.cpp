#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t x = s.find('.');
    if (s[x-1] == '9')
        return answer("GOTO Vasilisa.");

    std::string t = s.substr(0, x);
    if (s[x+1] >= '5')
        ++t.back();

    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

