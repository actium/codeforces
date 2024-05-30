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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    const auto delta = [](unsigned u, unsigned v) {
        return u < v ? v - u : u - v;
    };

    integer k = 1, e = ~0u;
    for (size_t i = 0; i < n; ++i) {
        k += delta(a[i], b[i]);

        if (a[i] <= b[n] && b[n] <= b[i] || a[i] >= b[n] && b[n] >= b[i]) {
            e = 0;
        } else {
            e = std::min<unsigned>(e, delta(a[i], b[n]));
            e = std::min<unsigned>(e, delta(b[i], b[n]));
        }
    }

    answer(k + e);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n+1);
    std::cin >> a >> b;

    solve(a, b);
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
