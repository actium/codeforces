#include <iostream>
#include <vector>

#include <cmath>

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

void answer(const std::vector<double>& v)
{
    for (const double x : v)
        std::cout << std::fixed << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p, unsigned a, unsigned d)
{
    const size_t n = p.size();

    std::vector<double> t(n);
    for (size_t i = 0; i < n; ++i) {
        const double dt = double(p[i].second) / a, s = a * dt * dt / 2;
        t[i] = p[i].first + (s > d ? sqrt(2.0 * d / a) : dt + (d - s) / p[i].second);
    }

    for (size_t i = 1; i < n; ++i)
        t[i] = std::max(t[i], t[i-1]);

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned a, d;
    std::cin >> a >> d;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p, a, d);

    return 0;
}
