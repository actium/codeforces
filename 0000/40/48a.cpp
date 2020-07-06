#include <iostream>
#include <string>

bool test(const std::string& a, const std::string& b, const std::string& c)
{
    if (b != c)
        return false;

    return (a == "rock" && b == "scissors")
        || (a == "paper" && b == "rock")
        || (a == "scissors" && b == "paper");
}

void answer(char v)
{
    std::cout << v << '\n';
}

void solve(const std::string& f, const std::string& m, const std::string& s)
{
    if (test(f, m, s))
        return answer('F');

    if (test(m, f, s))
        return answer('M');

    if (test(s, f, m))
        return answer('S');

    answer('?');
}

int main()
{
    std::string f, m, s;
    std::cin >> f >> m >> s;

    solve(f, m, s);

    return 0;
}

