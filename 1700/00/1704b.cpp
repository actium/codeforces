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

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    unsigned lb = a[0], ub = a[0], k = 0;
    for (size_t i = 1; i < n; ++i) {
        lb = std::min(lb, a[i]);
        ub = std::max(ub, a[i]);
        if (ub - lb > 2 * x) {
            lb = a[i];
            ub = a[i];
            ++k;
        }
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
