#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned m)
{
    const size_t k = n / 9 + 1;

    const std::string a(k, '9');
    answer(a, a + std::string(k-1, '0') + "1");
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

