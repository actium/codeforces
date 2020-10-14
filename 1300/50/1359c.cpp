#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned h, unsigned c, unsigned t)
{
    if (h <= t)
        return answer(1);

    const unsigned hc = h + c;
    if (2 * t <= hc)
        return answer(2);

    const long long k = (h - t) / (2 * t - hc);

    const long long k1 = 2 * k + 1;
    const long long k3 = 2 * k + 3;

    const auto d1 = llabs(k * hc + h - t * k1) * k3;
    const auto d2 = llabs(k * hc + hc + h - t * k3) * k1;

    answer(d1 <= d2 ? k1 : k3);
}

void test_case()
{
    unsigned h, c, t;
    std::cin >> h >> c >> t;

    solve(h, c, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

