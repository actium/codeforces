#include <iostream>
#include <set>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned l)
{
    std::set<unsigned> s;
    for (unsigned p = 1; p <= l; p *= a) {
        for (unsigned q = p; q <= l; q *= b) {
            if (l % q == 0)
                s.insert(l / q);
        }
    }

    answer(s.size());
}

void test_case()
{
    unsigned a, b, l;
    std::cin >> a >> b >> l;

    solve(a, b, l);
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
