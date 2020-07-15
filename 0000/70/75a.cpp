#include <iostream>
#include <string>

void remove_zeroes(std::string& s)
{
    for (size_t i = s.find('0'); i != std::string::npos; i = s.find('0', i))
        s.erase(i, 1);
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b)
{
    std::string x = std::to_string(a);
    std::string y = std::to_string(b);
    std::string z = std::to_string(a + b);

    remove_zeroes(x);
    remove_zeroes(y);
    remove_zeroes(z);

    answer(std::stoi(x) + std::stoi(y) == std::stoi(z));
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

