#include <iostream>
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

integer evaluate(const std::vector<unsigned>& a, unsigned h)
{
    integer v = 0;
    for (const unsigned x : a) {
        if (x < h)
            v += h - x;
    }
    return v;
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const integer n = a.size();

    unsigned lb = 1, ub = 2000000001;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (evaluate(a, mid) <= x ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
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
