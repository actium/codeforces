#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    std::string c;
    while (c.length() < n)
        c += "ROYG";

    c.resize(n - 3);
    c += "BIV";

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

