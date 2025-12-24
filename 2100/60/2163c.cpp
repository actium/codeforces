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

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a[0].size();

    std::vector<unsigned> lb1(n), ub1(n);
    lb1[0] = a[0][0];
    ub1[0] = a[0][0];
    for (size_t j = 1; j < n; ++j) {
        lb1[j] = std::min(lb1[j-1], a[0][j]);
        ub1[j] = std::max(ub1[j-1], a[0][j]);
    }

    std::vector<unsigned> lb2(n), ub2(n);
    lb2[n-1] = a[1][n-1];
    ub2[n-1] = a[1][n-1];
    for (size_t j = n-2; ~j != 0; --j) {
        lb2[j] = std::min(lb2[j+1], a[1][j]);
        ub2[j] = std::max(ub2[j+1], a[1][j]);
    }

    std::vector<unsigned> t(1 + 2 * n, 2 * n + 1);
    for (size_t j = 0; j < n; ++j) {
        const unsigned lb = std::min(lb1[j], lb2[j]), ub = std::max(ub1[j], ub2[j]);
        t[lb] = std::min(t[lb], ub);
    }

    for (size_t i = 2 * n; i > 1; --i)
        t[i-1] = std::min(t[i-1], t[i]);

    integer k = 0;
    for (size_t i = 1; i <= 2 * n; ++i)
        k += t[0] - t[i];

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(2, std::vector<unsigned>(n));
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
