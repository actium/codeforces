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

void solve(std::vector<unsigned>& c, unsigned l, unsigned r, unsigned x)
{
    const size_t n = c.size(), m = 1 << n;

    std::sort(c.begin(), c.end());

    unsigned k = 0;
    for (unsigned i = 0; i < m; ++i) {
        if (__builtin_popcount(i) < 2)
            continue;

        const size_t li = __builtin_ctz(i), ri = 31 - __builtin_clz(i);
        if (c[ri] - c[li] < x)
            continue;

        unsigned s = 0;
        for (size_t j = li; j <= ri; ++j) {
            if (i & 1 << j)
                s += c[j];
        }

        k += (s >= l && s <= r);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned l, r, x;
    std::cin >> l >> r >> x;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, l, r, x);

    return 0;
}
