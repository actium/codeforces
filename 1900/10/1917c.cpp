#include <iostream>
#include <vector>

using integer = long long;

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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& v, size_t d)
{
    const size_t n = a.size(), k = v.size();

    integer s = 0;
    for (size_t i = 0; i < n; ++i)
        s += (a[i] == i + 1);

    integer t = 0;
    for (size_t i = 0; i < std::min(2 * n, d); ++i) {
        t = std::max<integer>(t, s + (d - i - 1) / 2);

        for (size_t j = 0; j < v[i % k]; ++j) {
            s -= (a[j] == j + 1);
            ++a[j];
            s += (a[j] == j + 1);
        }
    }

    answer(t);
}

void test_case()
{
    size_t n, k, d;
    std::cin >> n >> k >> d;

    std::vector<unsigned> a(n), v(k);
    std::cin >> a >> v;

    solve(a, v, d);
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
