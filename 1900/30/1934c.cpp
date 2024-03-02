#include <iostream>

unsigned query(unsigned x, unsigned y)
{
    std::cout << '?' << ' ' << 1 + x << ' ' << 1 + y << std::endl;

    unsigned d;
    std::cin >> d;
    return d;
}

void answer(unsigned x, unsigned y)
{
    std::cout << '!' << ' ' << 1 + x << ' ' << 1 + y << std::endl;
}

void solve(unsigned n, unsigned m)
{
    const unsigned d = query(0, 0);

    if (d < m) {
        const unsigned e = query(0, d) / 2;
        if (e <= d && query(e, d - e) == 0)
            return answer(e, d - e);
    } else {
        const unsigned e = (query(d - m, m - 1) + 1) / 2;
        if (e <= m && query(d - m + e, m - e) == 0)
            return answer(d - m + e, m - e);
    }

    if (d < n) {
        const unsigned e = query(d, 0) / 2;
        answer(d - e, e);
    } else {
        const unsigned e = (query(n - 1, d - n) + 1) / 2;
        answer(n - e, d - n + e);
    }
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
