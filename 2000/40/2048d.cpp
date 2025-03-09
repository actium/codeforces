#include <algorithm>
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

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t m = b.size();

    std::sort(std::next(a.begin()), a.end());

    std::vector<integer> c(m);
    for (size_t i = 0; i < m; ++i) {
        if (b[i] > a[0])
            c[i] = a.end() - std::lower_bound(std::next(a.begin()), a.end(), b[i]);
    }

    std::sort(c.begin(), c.end());

    std::vector<integer> v(m);
    for (size_t i = 0; i < m; ++i) {
        v[i] = m / (i + 1);

        for (size_t j = i; j < m; j += i + 1)
            v[i] += c[j];
    }

    answer(v);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
