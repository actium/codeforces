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

void solve(const std::vector<unsigned>& a, unsigned s)
{
    const size_t n = a.size();

    std::vector<integer> x(n), y(n);
    x[0] = y[0] = a[0];
    for (size_t i = 1; i + 1 < n; ++i) {
        if (a[i] > s)
            x[i] = std::min(s, a[i] - s);

        y[i] = a[i] - x[i];
    }
    x[n-1] = y[n-1] = a[n-1];

    std::vector<integer> v(2);
    for (size_t i = 1; i < n; ++i) {
        v = {
            std::min(v[0] + y[i-1] * x[i], v[1] + x[i-1] * x[i]),
            std::min(v[1] + x[i-1] * y[i], v[0] + y[i-1] * y[i]),
        };
    }

    answer(v[0]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, s);
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
