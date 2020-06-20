#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    answer(a == b ? a : "1");
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

