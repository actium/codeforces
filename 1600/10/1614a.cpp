#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(std::vector<unsigned>& a, unsigned l, unsigned r, unsigned k)
{
    std::sort(a.begin(), a.end());

    const auto lb = std::lower_bound(a.begin(), a.end(), l);
    const auto ub = std::upper_bound(a.begin(), a.end(), r);

    const unsigned c = std::count_if(lb, ub, [q = k + 0ll](unsigned x) mutable {
        q -= int(x);
        return q >= 0;
    });

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned l, r, k;
    std::cin >> l >> r >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, l, r, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
