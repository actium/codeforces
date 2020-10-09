#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned k, unsigned a, unsigned b, unsigned v)
{
    const unsigned r = (a + v - 1) / v;

    const unsigned f = b / (k - 1);
    const unsigned p = b % (k - 1);
    const unsigned t = (a + v - 1) / v;

    if (f * k >= t)
        return answer((t + k - 1) / k);

    if (f * k + p + 1 >= t)
        return answer(f + 1);

    answer(t - f * k - p + f);
}

int main()
{
    unsigned k, a, b, v;
    std::cin >> k >> a >> b >> v;

    solve(k, a, b, v);

    return 0;
}

