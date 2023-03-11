#include <iostream>

void answer(const unsigned x[2], const unsigned y[2])
{
    std::cout << x[0] << ' ' << x[1] << ' ' << y[0] << ' ' << y[1] << '\n';
}

void solve(unsigned n)
{
    const auto allocate = [&](unsigned k, unsigned& w, unsigned& b, unsigned& s) {
        w += k / 2;
        b += k / 2;

        if (k % 2 == 1)
            s % 2 == 0 ? ++w : ++b;

        s += k;
    };

    unsigned a[2] = {}, b[2] = {}, s = 0;
    for (unsigned s = 0, d = 1; s < n; d += 8) {
        allocate(std::min(d, n - s), a[0], a[1], s);
        allocate(std::min(d + 4, n - s), b[0], b[1], s);
    }

    answer(a, b);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
