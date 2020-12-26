#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(integer r)
{
    if (r < 5 || r % 2 == 0)
        return no_answer();

    answer(1, (r - 3) / 2);
}

int main()
{
    integer r;
    std::cin >> r;

    solve(r);

    return 0;
}

