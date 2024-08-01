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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    integer s = 0;
    for (unsigned t = 0; t < 2; ++t) {
        std::vector<unsigned> f(1+n);
        unsigned mad = 0;
        for (unsigned& x : a) {
            s += x;

            if (++f[x] == 2 && x > mad)
                mad = x;

            x = mad;
        }
    }

    for (size_t i = 0; i < n; ++i)
        s += a[i] * integer(n - i);

    answer(s);
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
