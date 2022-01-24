#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned v1, unsigned v2, unsigned t, unsigned d)
{
    unsigned p = 0;
    while (t-- > 0) {
        p += v1;

        v1 = std::min(v1 + d, v2 + (t - 1) * d);
    }

    answer(p);
}

int main()
{
    unsigned v1, v2;
    std::cin >> v1 >> v2;

    unsigned t, d;
    std::cin >> t >> d;

    solve(v1, v2, t, d);

    return 0;
}
