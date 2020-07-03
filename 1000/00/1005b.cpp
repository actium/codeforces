#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n1 = s.length();
    const size_t n2 = t.length();

    size_t k = 0;
    while (k < n1 && k < n2 && s[n1-1-k] == t[n2-1-k])
        ++k;

    answer(n1 - k + n2 - k);
}

int main()
{
    std::string s;
    std::cin >> s;

    std::string t;
    std::cin >> t;

    solve(s, t);

    return 0;
}

