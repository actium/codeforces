#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<double, double>>& v)
{
    for (const std::pair<double, double>& x : v)
        std::cout << std::fixed << x.first << ' ' << x.second << '\n';
}

void solve(unsigned a, unsigned d, unsigned n)
{
    const auto f = [=](unsigned q) {
        unsigned x = 1ull * q * d % (4 * a);
        if (x < a)
            return std::make_pair(x / 10000.0, 0.0);

        x -= a;
        if (x < a)
            return std::make_pair(a / 10000.0, x / 10000.0);

        x -= a;
        if (x < a)
            return std::make_pair((a - x) / 10000.0, a / 10000.0);

        x -= a;
        return std::make_pair(0.0, (a - x) / 10000.0);
    };

    std::vector<std::pair<double, double>> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = f(i + 1);

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    double a, d;
    std::cin >> a >> d;

    unsigned n;
    std::cin >> n;

    solve(a * 10000 + 0.5, d * 10000 + 0.5, n);

    return 0;
}
