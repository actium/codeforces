#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double x, double y, double z)
{
    std::cout << std::fixed << x << ' ' << y << ' ' << z << '\n';
}

void solve(const std::vector<unsigned>& a, size_t t, double c, const std::vector<unsigned>& r)
{
    const size_t n = a.size();

    std::vector<double> vr(n);
    {
        double s = 0;
        for (size_t i = 0; i < n; ++i) {
            if (i >= t)
                s -= a[i-t];

            s += a[i];

            vr[i] = s / t;
        }
    }

    std::vector<double> va(n);
    {
        double mean = 0;
        for (size_t i = 0; i < n; ++i) {
            mean = (mean + double(a[i]) / t) / c;
            va[i] = mean;
        }
    }

    for (const unsigned q : r)
        answer(vr[q-1], va[q-1], std::abs(va[q-1] - vr[q-1]) / vr[q-1]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, t;
    std::cin >> n >> t;

    double c;
    std::cin >> c;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> r(m);
    std::cin >> r;

    solve(a, t, c, r);

    return 0;
}
