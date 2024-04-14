#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& p, unsigned x, unsigned a, unsigned y, unsigned b, integer k)
{
    const size_t n = p.size();

    for (size_t i = 0; i < n; ++i)
        p[i] /= 100;

    std::sort(p.begin(), p.end(), std::greater<unsigned>());

    if (x < y) {
        std::swap(x, y);
        std::swap(a, b);
    }

    const integer m = std::lcm<integer>(a, b);

    const auto check = [&](unsigned ub) {
        const unsigned cab = ub / m, ca = ub / a - cab, cb = ub / b - cab;

        integer s = 0;
        {
            for (size_t i = 0; i < cab; ++i)
                s += p[i] * (x + y);
            for (size_t i = 0; i < ca; ++i)
                s += p[cab+i] * x;
            for (size_t i = 0; i < cb; ++i)
                s += p[cab+ca+i] * y;
        }
        return s >= k;
    };

    if (!check(n))
        return no_answer();

    size_t lb = 0, ub = n;
    while (lb + 1 < ub) {
        const size_t mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    unsigned x, a;
    std::cin >> x >> a;

    unsigned y, b;
    std::cin >> y >> b;

    integer k;
    std::cin >> k;

    solve(p, x, a, y, b, k);
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
