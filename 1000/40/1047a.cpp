#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

int main()
{
    unsigned n;
    std::cin >> n;

    if ((n - 2) % 3 != 0) {
        answer(n-2, 1, 1);
    } else {
        answer(n-3, 2, 1);
    }

    return 0;
}

