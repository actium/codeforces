#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size(), m = b.size();

    std::vector<size_t> p(1+m);
    for (size_t i = 0, j = 0; i < m; ++i) {
        while (j < n && a[j] < b[i])
            ++j;

        p[1+i] = std::min(++j, n+1);
    }

    if (p[m] <= n)
        return answer(0);

    std::vector<size_t> s(m+1);
    for (size_t i = 0, j = 0; i < m; ++i) {
        while (j < n && a[n-1-j] < b[m-1-i])
            ++j;

        s[m-1-i] = std::min(++j, n+1);
    }

    unsigned k = ~0u;
    for (size_t i = 0; i < m; ++i) {
        if (p[i] + s[i+1] <= n)
            k = std::min(k, b[i]);
    }

    k != ~0u ? answer(k) : no_answer();
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