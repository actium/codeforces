#include <iostream>
#include <string>

void solve(const std::string& n)
{
    for (auto it = n.cbegin(), end = n.cend(); it != end; ++it)
        std::cout << *it;

    for (auto it = n.crbegin(), end = n.crend(); it != end; ++it)
        std::cout << *it;

    std::cout << '\n';
}

int main()
{
    std::string n;
    std::cin >> n;

    solve(n);

    return 0;
}

