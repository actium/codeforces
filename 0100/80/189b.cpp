#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned w, unsigned h)
{
    unsigned long long k = 0;
    for (unsigned d1 = 2; d1 <= w; d1 += 2) {
        for (unsigned d2 = 2; d2 <= h; d2 += 2)
            k += (h - d2 + 1) * (w - d1 + 1);
    }

    answer(k);
}

int main()
{
    unsigned w, h;
    std::cin >> w >> h;

    solve(w, h);

    return 0;
}

