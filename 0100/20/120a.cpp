#include <iostream>
#include <string>

void answer(char v)
{
    std::cout << v << '\n';
}

void solve(const std::string& d, unsigned a)
{
    answer((d == "front" && a == 1) || (d == "back" && a == 2) ? 'L' : 'R');
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::string d;
    std::cin >> d;

    unsigned a;
    std::cin >> a;

    solve(d, a);

    return 0;
}

