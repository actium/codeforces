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

void solve(size_t n, const std::vector<unsigned>& a)
{
    const size_t m = a.size();

    std::vector<unsigned> s(n);
    for (size_t i = 0; i < m; ++i)
        ++s[a[i]-1];

    const auto f = [&](int t) -> bool {
        unsigned k = 0;
        for (size_t i = 0; i < n; ++i) {
            if (s[i] >= t) {
                k += t;
            } else {
                k += s[i] + (t - s[i]) / 2;
            }
        }
        return k >= m;
    };

    int lb = -1, ub = 2 * m;
    while (lb + 1 < ub) {
        const int mid = (lb + ub) / 2;
        (f(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
