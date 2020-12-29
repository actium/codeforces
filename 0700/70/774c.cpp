#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    std::string x(n / 2, '1');

    if (n % 2 == 1)
        x[0] = '7';

    answer(x);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

