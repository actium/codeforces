#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned p, unsigned d, unsigned t, unsigned f, unsigned c)
{
    if (p >= d)
        return answer(0);

    unsigned k = 0;
    for (double x = t * p; ; ++k) {
        x += p * x / (d - p);
        if (x >= c)
            break;

        x += (x / d + f) * p;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned p, d, t, f, c;
    std::cin >> p >> d >> t >> f >> c;

    solve(p, d, t, f, c);

    return 0;
}
