#include <algorithm>
#include <array>
#include <iostream>
#include <string>

void solve(const std::string& a, const std::array<std::string, 10>& x)
{
    for (size_t i = 0; i < 8; ++i) {
        const std::string b = a.substr(i * 10, 10);
        std::cout << std::find(x.cbegin(), x.cend(), b) - x.cbegin();
    }
    std::cout << '\n';
}

int main()
{
    std::string a;
    std::cin >> a;

    std::array<std::string, 10> x;
    for (size_t i = 0; i < 10; ++i)
        std::cin >> x[i];

    solve(a, x);

    return 0;
}

