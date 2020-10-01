#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

template <typename T>
double x(const T begin, const T end, double t, int dv)
{
    double x = *begin, v = dv;
    for (T it = std::next(begin); it != end; ++it) {
        const double dt = (*it - x) / v;
        if (dt <= t) {
            x += v * dt;
            v += dv;
            t -= dt;
        } else {
            x += v * t;
            break;
        }
    }
    return x;
}

void solve(const std::vector<unsigned>& a)
{
    double ub = 1e9;
    for (double lb = 0; (ub - lb) / std::max(1.0, ub) > 1e-6; ) {
        const double t = (lb + ub) / 2;
        if (x(a.cbegin(), a.cend(), t, 1) >= x(a.crbegin(), a.crend(), t, -1))
            ub = t;
        else
            lb = t;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned l;
    std::cin >> l;

    std::vector<unsigned> a(n);
    std::cin >> a;

    a.insert(a.begin(), 0);
    a.push_back(l);

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

