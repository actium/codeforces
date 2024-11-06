#include <iostream>
#include <vector>

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> p(n);
    if (n % 2 == 1) {
        for (size_t i = 0; i < n; ++i)
            p[i] = i + 1;

        std::swap(p[0], p[1]);

        answer(n, p);
    } else {
        const unsigned msb = 1 << __builtin_clz(1) - __builtin_clz(n);

        for (size_t i = 0, x = 1; x < n; ++x) {
            if (x != 1 && x != msb-2 && x != msb-1)
                p[i++] = x;
        }

        p[n-4] = 1;
        p[n-3] = msb - 2;
        p[n-2] = msb - 1;
        p[n-1] = n;

        answer(2 * msb - 1, p);
    }
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
