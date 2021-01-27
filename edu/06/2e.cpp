#include <iostream>

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
    std::cout << std::fixed << v * v << '\n';
}

void solve(double c)
{
    answer(search(0, 100000, [c](double x) { return x * x * x * x + x >= c; }));
}

int main()
{
    double c;
    std::cin >> c;

    solve(c);

    return 0;
}

