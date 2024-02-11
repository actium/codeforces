#include <iostream>
#include <set>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x)
{
    const unsigned p = n - x, q = n + x - 2;

    std::set<unsigned> ds;
    for (unsigned i = 1; i * i <= q; ++i) {
        if (p % i == 0) {
            ds.insert(i);
            ds.insert(p / i);
        }
        if (q % i == 0) {
            ds.insert(i);
            ds.insert(q / i);
        }
    }

    unsigned c = 0;
    for (const unsigned d : ds) {
        if (d % 2 != 0 || (d + 2) / 2 < x)
            continue;

        const unsigned v = (n - 1) % d;
        if (v == x - 1 || d - v == x - 1)
            ++c;
    }

    answer(c);
}

void test_case()
{
    unsigned n, x;
    std::cin >> n >> x;

    solve(n, x);
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
