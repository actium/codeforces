#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& x, const std::string& y)
{
    unsigned z = 0;
    for (auto it = y.crbegin(); it != y.crend() && *it != '1'; ++it, ++z);

    unsigned k = 0;
    for (auto it = x.crbegin() + z; it != x.crend() && *it != '1'; ++it, ++k);

    answer(k);
}

void test_case()
{
    std::string x, y;
    std::cin >> x >> y;

    solve(x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

