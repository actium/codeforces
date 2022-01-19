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
    const size_t n = a.size(), m = b.size();

    std::vector<size_t> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[a[i]] = i;

    integer c = 0;
    for (size_t i = 0, j = 0; i < m; ++i) {
        const size_t x = p[b[i]];
        if (x > j) {
            c += 2 * (x - i);
            j = x;
        }

        ++c;
    }

    answer(c);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
