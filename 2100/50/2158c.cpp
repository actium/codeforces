#include <iostream>
#include <vector>

using integer = long long;

constexpr integer O = 0;

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

void solve(const std::vector<int>& a, const std::vector<unsigned>& b, size_t k)
{
    const size_t n = a.size();

    integer s[3] = { a[0], O + a[0] + b[0], O + a[0] + b[0] }, v[3] = { s[0], s[1], s[2] };
    for (size_t i = 1; i < n; ++i) {
        s[0] = std::max(O + a[i], s[0] + a[i]);
        v[0] = std::max(v[0], s[0]);

        s[2] = std::max(O + a[i] + b[i], s[0] + b[i]);
        v[2] = std::max(v[2], s[2]);

        s[1] = std::max(s[1] + a[i], s[2]);
        v[1] = std::max(v[1], s[1]);
    }

    answer(v[k % 2]);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b, k);
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
