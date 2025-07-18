#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::array<unsigned, 6>>& v)
{
    for (const std::array<unsigned, 6>& x : v) {
        for (size_t i = 0; i < 6; ++i)
            std::cout << x[i] << " \n"[i==5];
    }
}

void solve(size_t n, std::vector<unsigned>& a)
{
    const size_t m = a.size(), p = (n + 1) / 2, q = n - p;

    std::sort(a.begin(), a.end());

    std::vector<std::array<unsigned, 6>> s(n);
    for (size_t k = 0; k < 6; k += 2) {
        for (size_t i = 0; i < p; ++i) {
            s[i][k] = a[i];
            s[i][k+1] = a[m-p+i];
        }
        for (size_t i = 0; i < q; ++i) {
            s[p+i][k] = a[m-q+i];
            s[p+i][k+1] = a[i];
        }
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);
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
