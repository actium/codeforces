#include <iostream>

bool lucky(unsigned v)
{
    return v % 10 == 7 || v / 10 == 7;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned h, unsigned m, unsigned x)
{
    unsigned k = 0;
    while (!lucky(h) && !lucky(m)) {
        if (m < x) {
            m = (60 + m - x) % 60;
            h = (24 + h - 1) % 24;
        } else {
            m -= x;
        }
        ++k;
    }

    answer(k);
}

int main()
{
    unsigned x;
    std::cin >> x;

    unsigned hh, mm;
    std::cin >> hh >> mm;

    solve(hh, mm, x);

    return 0;
}

