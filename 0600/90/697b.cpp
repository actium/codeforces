#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t xd = s.find('.'), xe = s.find('e', xd + 1);

    std::string a = s.substr(0, xd);
    std::string d = s.substr(xd + 1, xe - (xd + 1));

    const unsigned b = std::stoi(s.substr(xe + 1));

    if (d.length() < b)
        d.resize(b, '0');

    a += d.substr(0, b);
    d.erase(0, b);

    if (!d.empty() && d != "0")
        a += '.' + d;

    answer(a);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
