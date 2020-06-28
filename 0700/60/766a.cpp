#include <iostream>
#include <string>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    if (s == t)
        return answer(-1);

    answer(std::max(s.size(), t.size()));
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

