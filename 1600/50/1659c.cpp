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

void solve(const std::vector<unsigned>& x, unsigned a, unsigned b)
{
    const size_t n = x.size();

    std::vector<integer> ss(1+n);
    for (size_t i = n; i > 0; --i)
        ss[i-1] = ss[i] + x[i-1];

    integer c = 0, p = 0, s = 0;
    for (size_t i = 0; i < n; ++i) {
        if ((ss[i] - (n - i) * c) * b > (p - c) * a + (ss[i] - (n - i) * p) * b) {
            s += (p - c) * a;
            c = p;
        }
        s += (x[i] - c) * b;
        p = x[i];
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, a, b);
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
