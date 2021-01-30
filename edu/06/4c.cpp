#include <algorithm>
#include <iostream>
#include <vector>

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
    return lb;
}

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p, size_t k)
{
    const size_t n = p.size();

    const auto f = [&](double x) {
        std::vector<double> a(n);
        for (size_t i = 0; i < n; ++i)
            a[i] = p[i].first - p[i].second * x;

        std::sort(a.begin(), a.end(), std::greater<double>());

        double s = 0;
        for (size_t i = 0; i < k; ++i)
            s += a[i];

        return s < 0;
    };

    answer(search(0, 100000, f));
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p, k);

    return 0;
}

