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

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& v)
{
    const size_t n = x.size();

    const auto f = [&](double p) {
        double t = 0;
        for (size_t i = 0; i < n; ++i)
            t = std::max(t, std::abs(p - x[i]) / v[i]);

        return t;
    };

    double lb = 1, ub = 1e9;
    while (std::abs(ub - lb) > 1e-6) {
        const double mid1 = lb + (ub - lb) / 3, mid2 = ub - (ub - lb) / 3;
        f(mid1) > f(mid2) ? lb = mid1 : ub = mid2;
    }

    answer(f(lb));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n), v(n);
    std::cin >> x >> v;

    solve(x, v);

    return 0;
}
