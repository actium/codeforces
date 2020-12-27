#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::string p)
{
    const integer n = std::stoll(p.substr(0, p.length() -1));

    integer t = (n - 1) / 4 * 16;
    if (n % 2 == 0)
        t += 7;

    constexpr unsigned d[6] = { 4, 5, 6, 3, 2, 1 };
    t += d[p.back() - 'a'];

    answer(t);
}

int main()
{
    std::string p;
    std::cin >> p;

    solve(p);

    return 0;
}

