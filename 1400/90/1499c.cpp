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

void solve(const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    unsigned x[2] = { c[0], c[1] };
    integer s = c[0] + c[1], q[2] = { n - 1, n - 1}, v = s * n;
    for (unsigned i = 2, j = 0; i < n; ++i, j ^= 1) {
        x[j] = std::min(x[j], c[i]);
        s += c[i];
        --q[j];
        v = std::min(v, s + x[0] * q[0] + x[1] * q[1]);
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);
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
