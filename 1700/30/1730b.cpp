#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& t)
{
    const size_t n = x.size();

    const auto f = [&](double p) {
        double s = 0;
        for (size_t i = 0; i < n; ++i)
            s = std::max(s, std::abs(x[i] - p) + t[i]);

        return s;
    };

    double lb = 0, ub = 100000000;
    for (unsigned i = 0; i < 80; ++i) {
        const double mid1 = lb + (ub - lb) / 3, mid2 = ub - (ub - lb) / 3;
        f(mid1) > f(mid2) ? lb = mid1 : ub = mid2;
    }

    answer((lb + ub) / 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n), t(n);
    std::cin >> x >> t;

    solve(x, t);
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
