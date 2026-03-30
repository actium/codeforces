#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

template <typename F>
void prepare(const std::vector<unsigned>& a, std::vector<int>& x, F&& locate)
{
    const size_t n = a.size();

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        const size_t j = locate(i);
        while (!q.empty() && a[q.back()] >= a[j])
            q.pop_back();

        if (!q.empty())
            x[j] = q.back();

        q.push_back(j);
    }
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<int> p(n, -1);
    prepare(a, p, [n](size_t i) { return i; });

    std::vector<int> s(n, n);
    prepare(a, s, [n](size_t i) { return n-1-i; });

    std::vector<unsigned> d(1+n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned x = a[i], v = s[i] - p[i] - 1;
        d[x] = (d[x] == 0 ? v : std::min(d[x], v));
    }
    for (size_t i = 2; i <= n; ++i) {
        if (d[i-1] == 0)
            d[i] = 0;
    }

    std::vector<unsigned> c(n+1);
    for (unsigned i = 1; i <= n; ++i) {
        ++c[0];
        --c[d[i]];
    }
    for (size_t i = 1; i <= n; ++i)
        c[i] += c[i-1];

    std::string t(n, '0');
    for (size_t i = 0; i < n; ++i)
        t[i] += (c[i] == n - i);

    answer(t);
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
