#include <iostream>
#include <string>

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::cout << 3 << '\n';
    std::cout << "L 2" << '\n';
    std::cout << "R 2" << '\n';
    std::cout << "R " << 2*n-1 << '\n';
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

