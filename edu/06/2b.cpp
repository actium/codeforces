#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const auto f = [=](double x) {
        unsigned c = 0;
        for (const unsigned d : a)
            c += d / x;

        return c < k;
    };

    answer(search(0, 10000000, f));
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

