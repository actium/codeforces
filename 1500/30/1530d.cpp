#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i)
        ++d[a[i]-1];

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (d[i] == 0)
            p.push_back(i);
    }

    std::vector<unsigned> v(n);
    for (size_t i = 0; i < n; ++i) {
        size_t x = a[i] - 1;
        if (d[x] > 1 && p.back() == i)
            continue;

        if (--d[x] != 0) {
            x = p.back();
            p.pop_back();
        }

        v[i] = 1 + x;
    }

    const auto it = std::find(v.begin(), v.end(), 0);
    if (it != v.end()) {
        const auto jt = std::find(d.begin(), d.end(), 1);
        *it = 1 + (jt - d.begin());
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k += (v[i] == a[i]);

    answer(k, v);
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
