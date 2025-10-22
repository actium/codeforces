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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<integer> p(n), q(n);
    for (size_t i = 0; i < n; ++i) {
        p[i] = 2LL * a[i] + i;
        q[i] = 2LL * a[i] - i;
    }

    for (size_t i = 2; i < n; i += 2) {
        p[i] = std::min(p[i], p[i-2]);
        q[i] = std::min(q[i], q[i-1]);
    }
    for (size_t i = 3; i < n; i += 2) {
        p[i] = std::max(p[i], p[i-2]);
        q[i] = std::max(q[i], q[i-2]);
    }

    integer s = a[0], d = n - (n % 2 == 0 ? 2 : 1);
    for (size_t i = 1; i < n; ++i) {
        if (i % 2 == 0) {
            s += a[i];
            d = std::max<integer>(d, q[i-1] - (2LL * a[i] - i));
        } else {
            s -= a[i];
            d = std::max<integer>(d, (2LL * a[i] + i) - p[i-1]);
        }
    }

    answer(s + d);
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
