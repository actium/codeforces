#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a)
{
    const std::string b(a.rbegin(), a.rend());

    answer(a + b);
}

int main()
{
    std::string a;
    std::cin >> a;

    solve(a);

    return 0;
}

