#include <iostream>
#include <vector>

#include <cmath>

void answer(const std::vector<double>& v)
{
    std::cout << v.size() << '\n';

    for (const double x : v)
        std::cout << std::fixed << x << '\n';
}

void infinity()
{
    std::cout << -1 << '\n';
}

void solve(int a, int b, int c)
{
    if (a == 0 && b == 0 && c == 0)
        return infinity();

    std::vector<double> x;
    if (a != 0) {
        const double d = 1.0 * b * b - 4.0 * a * c;
        if (d >= 0)
            x.push_back(0.5 * (-b + sqrt(d)) / a);
        if (d > 0)
            x.push_back(0.5 * (-b - sqrt(d)) / a);

        if (!x.empty() && x.front() > x.back())
            std::swap(x.front(), x.back());
    }
    if (a == 0 && b != 0)
        x.push_back(-double(c) / b);

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}
