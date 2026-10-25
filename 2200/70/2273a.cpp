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
    const auto check = [n](unsigned c) {
        unsigned r = n;
        for (unsigned i = n; i != 0; --i) {
            const unsigned k = c / i;
            r -= std::min(k * i, r);
        }
        return r == 0;
    };

    unsigned lb = 0, ub = n;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    std::vector<unsigned> p;
    for (unsigned i = n, x = 1; i != 0; --i) {
        for (unsigned k = ub / i; k != 0; --k)
            p.insert(p.end(), i, x++);
    }

    p.resize(n);

    answer(ub, p);
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
