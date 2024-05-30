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

void solve(size_t n, size_t m, const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t k = n + m + 1;

    std::vector<size_t> p, t;
    integer s = 0;
    for (size_t i = 0; i < k; ++i) {
        if ((a[i] > b[i] || t.size() > m) && p.size() <= n) {
            p.push_back(i);
            s += a[i];
        } else {
            t.push_back(i);
            s += b[i];
        }
    }

    std::vector<integer> v(k, s);
    for (const size_t x : p) {
        v[x] -= a[x];

        if (p.size() <= n) {
            v[x] -= b[t.back()];
            v[x] += a[t.back()];
        }
    }
    for (const size_t x : t) {
        v[x] -= b[x];

        if (t.size() <= m) {
            v[x] -= a[p.back()];
            v[x] += b[p.back()];
        }
    }

    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n + m + 1), b(n + m + 1);
    std::cin >> a >> b;

    solve(n, m, a, b);
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
