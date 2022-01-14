#include <algorithm>
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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size(), m = n / 2;

    std::sort(a.begin(), a.end());

    const auto f = [&](unsigned x) {
        unsigned long long d = 0;
        for (size_t i = m; i < n; ++i) {
            if (a[i] < x)
                d += x - a[i];
        }
        return d <= k;
    };

    unsigned lb = a[m], ub = lb + k + 1;
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

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

