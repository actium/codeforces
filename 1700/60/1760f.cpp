#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    if (x == oo)
        std::cout << "Infinity" << '\n';
    else
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(std::vector<unsigned>& a, integer c, integer d)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    if (d * a[0] < c)
        return no_answer();

    std::vector<integer> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    unsigned lb = 1, ub = d + 1;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (ps[std::min<unsigned>(mid, n)] * (d / mid) + ps[std::min<unsigned>(d % mid, n)] >= c ? lb : ub) = mid;
    }
    answer(lb == d ? oo : lb - 1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer c, d;
    std::cin >> c >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, c, d);
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
