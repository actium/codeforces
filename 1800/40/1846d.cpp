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

void solve(const std::vector<unsigned>& y, unsigned d, unsigned h)
{
    const size_t n = y.size();

    double t = 0.5 * d * h, s = t;
    for (size_t i = 1; i < n; ++i) {
        const unsigned dy = y[i] - y[i-1];
        if (dy < h) {
            const unsigned ph = h - dy;
            s -= 0.5 * d * ph * ph / h;
        }
        s += t;
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned d, h;
    std::cin >> d >> h;

    std::vector<unsigned> y(n);
    std::cin >> y;

    solve(y, d, h);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
