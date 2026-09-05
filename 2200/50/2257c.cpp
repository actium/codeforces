#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size();
    for (const unsigned x : v)
        std::cout << ' ' << x;

    std::cout << '\n';
}

void solve(const std::vector<unsigned>& p, std::vector<unsigned>& a)
{
    const size_t n = p.size() + 1, m = a.size();

    std::vector<unsigned> h(n);
    for (size_t i = 1; i < n; ++i)
        h[i] = h[p[i-1]-1] + 1;

    size_t x = 0;
    for (size_t i = 1; i < m; ++i) {
        if (h[a[i]-1] < h[a[x]-1])
            x = i;
    }

    a[x] = a.back();
    a.pop_back();

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(p, a);
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
