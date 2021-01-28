#include <iostream>
#include <vector>

#include <cfloat>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename F>
double search(double lb, double ub, F&& f)
{
    for (unsigned k = 0; k < 100; ++k) {
        const double mid = (lb + ub) / 2;
        if (f(mid))
            ub = mid;
        else
            lb = mid;
    }
    return (lb + ub) / 2;
}

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(const std::vector<std::pair<int, unsigned>>& p)
{
    const auto f = [&](double t) {
        double lb = -1000000001 * t, ub = 1000000001 * t;
        for (const auto [x, v] : p) {
            lb = std::max(lb, x - v * t);
            ub = std::min(ub, x + v * t);
        }
        return lb <= ub;
    };

    answer(search(0, 1000000000, f));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, unsigned>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

