#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t)
{
    std::string s;

    size_t i = 0;
    if (t[0] == 'h') {
        s += "http://";
        i += 4;
    } else {
        s += "ftp://";
        i += 3;
    }

    const size_t j = t.find("ru", i + 1);
    s += t.substr(i, j - i);
    s += ".ru";

    if (j + 2 < t.length())
        s += "/" + t.substr(j + 2);

    answer(s);
}

int main()
{
    std::string t;
    std::cin >> t;

    solve(t);

    return 0;
}

