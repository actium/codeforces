#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a1, unsigned a2)
{
    unsigned t = 0;
    while (a1 > 0 && a2 > 0 && a1 + a2 > 2) {
        if (a1 < a2) {
            ++a1, a2 -= 2;
        } else {
            ++a2, a1 -= 2;
        }
        ++t;
    }

    answer(t);
}

int main()
{
    unsigned a1, a2;
    std::cin >> a1 >> a2;

    solve(a1, a2);

    return 0;
}

