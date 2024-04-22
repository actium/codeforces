#include <iostream>

unsigned query(unsigned r, unsigned c)
{
    std::cout << '?' << ' ' << r << ' ' << c << std::endl;

    unsigned d;
    std::cin >> d;
    return d;
}

void answer(unsigned x, unsigned y)
{
    std::cout << '!' << ' ' << x << ' ' << y << std::endl;
}

void solve(unsigned n, unsigned m)
{
    const unsigned d1 = query(1, 1);
    if (d1 >= m) {
        const unsigned r = 1 + d1;
        return answer(r, 1 + query(r, 1));
    }
    if (d1 >= n) {
        const unsigned c = 1 + d1;
        return answer(1 + query(1, c), c);
    }

    const unsigned d2 = query(1, 1 + d1);
    if (d2 != d1)
        return answer(1 + d2, 1 + d1);

    const unsigned d3 = query(1 + d1, 1);
    if (d3 != d1)
        return answer(1 + d1, 1 + d3);

    answer(1 + d1, 1 + d1);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
