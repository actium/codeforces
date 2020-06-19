#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

int main()
{
    unsigned n;
    std::cin >> n;

    if (n % 2 == 0) {
        answer(n + 4, 4);
    } else {
        answer(n + 9, 9);
    }

    return 0;
}

