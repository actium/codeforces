#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned l;
    std::cin >> l;

    std::vector<unsigned> a(n);
    std::cin >> a;

    unsigned k = (a[0] > l);
    for (size_t i = 1; i < n; ++i)
        k += (a[i] > l && a[i-1] <= l);

    const auto increase = [&](size_t i, unsigned d) {
        a[i] += d;

        if (a[i] <= l)
            return;

        if (n == 1 || (i == 0 && a[i+1] <= l) || (i == n-1 && a[i-1] <= l))
            ++k;

        if (i > 0 && i < n-1) {
            k -= (a[i-1] > l && a[i+1] > l);
            k += (a[i-1] <= l && a[i+1] <= l);
        }
    };

    for (size_t i = 0; i < m; ++i) {
        unsigned t;
        std::cin >> t;

        if (t == 0) {
            std::cout << k << '\n';
        } else {
            unsigned p, d;
            std::cin >> p >> d;
            --p;

            if (a[p] <= l)
                increase(p, d);
        }
    }

    return 0;
}

