#include <iostream>
#include <string>
#include <vector>

using point_t = std::pair<size_t, size_t>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::string>& a)
{
    const size_t n = a.size();

    std::vector<size_t> lr(10, n), ur(10), lc(10, n), uc(10);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            const size_t x = a[i][j] - '0';

            lr[x] = std::min(lr[x], i);
            ur[x] = std::max(ur[x], i);
            lc[x] = std::min(lc[x], j);
            uc[x] = std::max(uc[x], j);
        }
    }

    std::vector<unsigned> c(10);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            const size_t x = a[i][j] - '0';

            const unsigned dr = std::max(i, n-1-i), dc = std::max(j, n-1-j);
            if (i > lr[x])
                c[x] = std::max(c[x], unsigned(i - lr[x]) * dc);
            if (i < ur[x])
                c[x] = std::max(c[x], unsigned(ur[x] - i) * dc);
            if (j > lc[x])
                c[x] = std::max(c[x], dr * unsigned(j - lc[x]));
            if (j < uc[x])
                c[x] = std::max(c[x], dr * unsigned(uc[x] - j));
        }
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
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
