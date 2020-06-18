#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t)
{
    const size_t n = t.length();

    std::string s;
    for (size_t i = 0, j = 1; i < n; i += j, ++j)
        s.push_back(t[i]);

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string t;
    std::cin >> t;

    solve(t);

    return 0;
}

