#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length(), m = t.length();

    unsigned k = 0;
    for (size_t i = 0; i = s.find(t, i), i != std::string::npos; i += m)
        ++k;

    answer(k);
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

