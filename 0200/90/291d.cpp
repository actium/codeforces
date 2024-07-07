#include <iostream>
#include <vector>

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> a(1+n, 1);
    a[n] = 0;

    while (k-- != 0) {
        std::vector<unsigned> b(1+n);
        for (unsigned i = 1; i < n; ++i) {
            const unsigned d = (n - i) - a[i];

            unsigned c = n;
            while (c > 1 && a[c-1] <= d)
                --c;

            std::cout << c << ' ';

            b[i] = a[i] + a[c];
        }
        std::cout << n << '\n';

        std::swap(a, b);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
