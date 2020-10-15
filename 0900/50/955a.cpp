#include <iostream>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(unsigned t, unsigned h, unsigned d, unsigned c, unsigned n)
{
    constexpr unsigned tb = 20 * 60;

    const unsigned ki = (h + n - 1) / n;
    if (t >= tb)
        return answer(ki * c * 0.8);

    const unsigned hl = h + d * (tb - t);
    const unsigned kl = (hl + n - 1) / n;

    answer(std::min(ki * c * 1.0, kl * c * 0.8));
}

int main()
{
    unsigned hh, mm;
    std::cin >> hh >> mm;

    unsigned h, d, c, n;
    std::cin >> h >> d >> c >> n;

    solve(hh * 60 + mm, h, d, c, n);

    return 0;
}

