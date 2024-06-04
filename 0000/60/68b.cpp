#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const auto check = [&](double x) {
        double b = 0, d = 0;
        for (const unsigned q : a) {
            if (q > x) {
                b += q - x;
            } else {
                d += x - q;
            }
        }
        return 100 * d / (100 - k) <= b;
    };

    double lb = 0, ub = 1001;
    for (unsigned i = 0; i < 100; ++i) {
        const double mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
