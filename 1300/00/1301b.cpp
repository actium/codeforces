#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    int lb = 1000000000, ub = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == -1 && a[i-1] != -1) {
            lb = std::min(lb, a[i-1]);
            ub = std::max(ub, a[i-1]);
        }
        if (a[i] != -1 && a[i-1] == -1) {
            lb = std::min(lb, a[i]);
            ub = std::max(ub, a[i]);
        }
    }

    const unsigned k = (lb + ub) / 2;

    if (a[0] == -1)
        a[0] = k;

    unsigned m = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == -1)
            a[i] = k;

        m = std::max<unsigned>(m, std::abs(a[i] - a[i-1]));
    }

    answer(m, k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
