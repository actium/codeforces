#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned spread(unsigned x)
{
    std::pair<unsigned, unsigned> r = { 9, 0 };
    do {
        const unsigned d = x % 10;
        r.first = std::min(r.first, d);
        r.second = std::max(r.second, d);
        x /= 10;
    } while (x != 0);

    return r.second - r.first;
}

void solve(unsigned lb, unsigned ub)
{
    std::pair<unsigned, unsigned> r = std::make_pair(spread(lb), lb);
    for (unsigned i = 1; i < 100 && lb + i <= ub; ++i) {
        const unsigned d = spread(lb + i);
        if (d > r.first) {
            r.first = d;
            r.second = lb + i;
        }
    }

    answer(r.second);
}

void test_case()
{
    unsigned lb, ub;
    std::cin >> lb >> ub;

    solve(lb, ub);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
