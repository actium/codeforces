#include <iostream>
#include <vector>

constexpr double oo = 1e20;

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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned m, const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    const auto check = [&](double x) {
        x -= (x + m) / a[0];
        if (x < 0)
            return false;

        for (size_t i = 1; i < n; ++i) {
            x -= (x + m) / b[i];
            if (x < 0)
                return false;

            x -= (x + m) / a[i];
            if (x < 0)
                return false;
        }

        return x - (x + m) / b[0] >= 0;
    };

    double lb = 0, ub = oo;
    for (unsigned i = 0; i < 100; ++i) {
        const double mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    ub == oo ? no_answer() : answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(m, a, b);

    return 0;
}
