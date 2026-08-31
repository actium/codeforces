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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b = a;
    std::sort(b.begin(), b.end());

    std::vector<unsigned> c(1+n);
    for (size_t i = 0; i < n; ++i) {
        unsigned f[3] = {};
        for (size_t j = i; j < n; ++j) {
            ++f[(a[j] >= b[n/2]) + (a[j] > b[n/2])];

            if ((j - i) % 2 != 0 || f[0] + f[1] <= f[2] || f[1] + f[2] <= f[0])
                continue;

            if (i == 0 || c[i] != 0)
                c[j+1] = std::max(c[j+1], c[i] + 1);
        }
    }

    answer(c[n]);
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
