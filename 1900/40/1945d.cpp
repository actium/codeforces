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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t m)
{
    integer c = 0, d = 0, v = ~integer(0);
    for (size_t i = a.size() - 1; ~i != 0; --i) {
        c = std::min(c, d) + a[i];
        d = std::min(c, d + b[i]);

        if (i < m)
            v = std::min(v, c);
    }

    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, m);
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
