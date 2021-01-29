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
    return lb;
}

void answer(unsigned l, unsigned r)
{
    std::cout << l << ' ' << r << '\n';
}

void solve(const std::vector<unsigned>& a, size_t d)
{
    const size_t n = a.size();

    const auto f = [&](double x) {
        std::vector<double> p(1+n);
        for (size_t i = 1; i <= n; ++i)
            p[i] = p[i-1] + (a[i-1] - x);

        std::vector<double> q(1+n);
        for (size_t i = 1; i <= n; ++i)
            q[i] = std::min(p[i], q[i-1]);

        for (size_t r = d; r <= n; ++r) {
            if (q[r-d] <= p[r])
                return false;
        }
        return true;
    };

    const double x = search(0, 100, f);

    std::vector<double> p(1+n);
    for (size_t i = 1; i <= n; ++i)
        p[i] = p[i-1] + (a[i-1] - x);

    std::vector<size_t> q(1+n);
    for (size_t i = 1, j = 0; i <= n; ++i) {
        if (p[i] < p[j])
            j = i;

        q[i] = j;
    }

    for (size_t r = d; r <= n; ++r) {
        const size_t l = q[r-d];
        if (p[l] <= p[r])
            return answer(l+1, r);
    }
}

int main()
{
    size_t n, d;
    std::cin >> n >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, d);

    return 0;
}

