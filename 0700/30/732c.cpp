#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer b, integer d, integer s)
{
    if (b >= d && b >= s)
        return answer(std::max(b-1, d) - d + std::max(b-1, s) - s);

    if (d >= b && d >= s)
        return answer(std::max(d-1, b) - b + std::max(d-1, s) - s);

    answer(std::max(s-1, b) - b + std::max(s-1, d) - d);
}

int main()
{
    integer b, d, s;
    std::cin >> b >> d >> s;

    solve(b, d, s);

    return 0;
}

