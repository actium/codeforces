#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& n1, const std::string& n2)
{
    const size_t n = n1.length();
    for (size_t i = 0; i < n; ++i)
        n1[i] = '0' + (n1[i] ^ n2[i]);

    answer(n1);
}

int main()
{
    std::string n1, n2;
    std::cin >> n1 >> n2;

    solve(n1, n2);

    return 0;
}

