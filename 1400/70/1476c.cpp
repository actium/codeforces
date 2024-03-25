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

void solve(const std::vector<unsigned>& c, const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = c.size();

    integer s = 0, t = c[n-1] - 1;
    for (size_t i = n - 1; i > 0; --i) {
        s = std::max(s, t + 2 + std::abs(a[i] - b[i]));

        if (a[i] == b[i]) {
            t = c[i-1] - 1;
        } else {
            const unsigned u = std::min(a[i], b[i]), v = std::max(a[i], b[i]);

            t = std::max<integer>(t + 2 + (u - 1) + (c[i-1] - v), c[i-1] - 1);
        }
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<int> a(n), b(n);
    std::cin >> a >> b;

    solve(c, a, b);
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
