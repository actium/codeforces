#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size() / 2;

    std::vector<std::pair<unsigned, unsigned>> f(1 + n);
    for (size_t i = 0; i < n; ++i) {
        ++f[a[i]].first;
        ++f[a[n+i]].second;
    }

    std::vector<unsigned> u, v;
    for (unsigned i = 1; i <= n; ++i) {
        if (f[i].first == 2) {
            u.push_back(i);
            u.push_back(i);
        }
        if (f[i].second == 2) {
            v.push_back(i);
            v.push_back(i);
        }
    }
    for (unsigned i = 1; i <= n; ++i) {
        if (f[i].first == 1) {
            u.push_back(i);
            v.push_back(i);
        }
    }

    u.resize(2 * k);
    v.resize(2 * k);

    answer(u, v);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a, k);
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
