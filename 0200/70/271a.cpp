#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

bool check(unsigned y)
{
    unsigned digits = 0;
    while (y != 0) {
        const unsigned digit = y % 10;
        if (digits & (1 << digit))
            return false;

        digits |= 1 << digit;
        y /= 10;
    }
    return true;
}

void solve(unsigned y)
{
    while (!check(++y));

    answer(y);
}

int main()
{
    unsigned y;
    std::cin >> y;

    solve(y);

    return 0;
}

