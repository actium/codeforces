#include <iostream>
#include <vector>

void answer(const std::vector<double>& v)
{
    const char* separator = "";
    for (const double x : v) {
        std::cout << separator << std::fixed << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned h)
{
    const double t = 0.5 * h / n;

    std::vector<double> v(n-1);
    for (unsigned i = 1; i < n; ++i) {
        double lb = 0, ub = 1;
        for (unsigned j = 0; j < 30; ++j) {
            const double k = (lb + ub) / 2;

            const double s = 0.5 * k * h * k;
            if (s < i * t)
                lb = k;
            else
                ub = k;
        }
        v[i-1] = ub * h;
    }

    answer(v);
}

int main()
{
    unsigned n, h;
    std::cin >> n >> h;

    solve(n, h);

    return 0;
}

