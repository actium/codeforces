#include <iostream>

void answer(char v)
{
    std::cout << v << '\n';
}

void solve(size_t x, size_t y, size_t z)
{
    if (x > y + z)
        return answer('+');

    if (y > x + z)
        return answer('-');

    if (x == y && z == 0)
        return answer('0');

    answer('?');
}

int main()
{
    size_t x, y, z;
    std::cin >> x >> y >> z;

    solve(x, y, z);

    return 0;
}

