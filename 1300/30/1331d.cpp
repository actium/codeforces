#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v;
}

void solve(const std::string& n)
{
    answer(n.back() % 2);
}

int main()
{
    std::string n;
    std::cin >> n;

    solve(n);

    return 0;
}

