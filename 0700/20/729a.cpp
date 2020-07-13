#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    for (size_t x = s.find("ogogo"); x != std::string::npos; x = s.find("ogogo", x))
        s.erase(x, 2);

    for (size_t x = s.find("ogo"); x != std::string::npos; x = s.find("ogo", x))
        s.replace(x, 3, "***");

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

