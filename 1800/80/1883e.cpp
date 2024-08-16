#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    integer k = 0, d = 0;
    for (size_t i = 1; i < n; ++i) {
        const unsigned lw = 32 - __builtin_clz(a[i-1]), rw = 32 - __builtin_clz(a[i]);
        if (lw >= rw) {
            d += lw - rw + (a[i-1] > (a[i] << lw - rw));
        } else {
            const unsigned e = rw - lw + (a[i] >= (a[i-1] << rw - lw)) - 1;
            d -= std::min<unsigned>(d, e);
        }

        k += d;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
