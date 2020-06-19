#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

int main()
{
    unsigned x;
    std::cin >> x;

    if (x != 1) {
        answer(x - x % 2, 2);
    } else {
        answer(-1);
    }

    return 0;
}

