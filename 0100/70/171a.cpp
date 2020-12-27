#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    std::string x = std::to_string(b);
    std::reverse(x.begin(), x.end());
    answer(a + std::stoi(x));
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

