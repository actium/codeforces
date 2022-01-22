#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned k)
{
    const size_t n = a.size();

    const auto f = [&](unsigned x) {
        unsigned q = k;
        for (size_t i = 0; i < n; ++i) {
            const unsigned long long r = 1ull * a[i] * x;
            if (b[i] >= r)
                continue;

            const unsigned long long d = r - b[i];
            if (d > q)
                return false;

            q -= d;
        }
        return true;
    };

    unsigned lb = 0, ub = 2000000001;
    while (lb + 1 < ub) {
        const unsigned mid = lb + (ub - lb) / 2;
        (f(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, k);

    return 0;
}
