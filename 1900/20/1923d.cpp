#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

std::vector<unsigned> search(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned long long> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    std::vector<size_t> x(n);
    for (size_t i = 1; i < n; ++i)
        x[i] = (a[i] == a[i-1] ? x[i-1] : i);

    const auto check = [&](size_t p, size_t q) {
        return (x[p-1] > q ? ps[p] - ps[q] : a[p-1]) > a[p];
    };

    std::vector<unsigned> d(n, oo);
    for (size_t i = 1; i < n; ++i) {
        if (!check(i, 0))
            continue;

        size_t lb = 0, ub = i;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            (check(i, mid) ? lb : ub) = mid;
        }

        d[i] = i - lb;
    }
    return d;
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const std::vector<unsigned> p = search(a);
    std::reverse(a.begin(), a.end());
    const std::vector<unsigned> s = search(a);

    std::vector<int> d(n);
    for (size_t i = 0; i < n; ++i)
        d[i] = std::min(p[i], s[n-1-i]);

    answer(d);
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
