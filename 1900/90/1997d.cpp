#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

unsigned traverse(const std::vector<std::vector<size_t>>& s, size_t u, const std::vector<unsigned>& a)
{
    if (s[u].empty())
        return a[u];

    unsigned x = ~0u;
    for (const size_t v : s[u])
        x = std::min(x, traverse(s, v, a));

    return u == 0 ? a[0] + x : std::min((a[u] + x) / 2, x);
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& p)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> s(n);
    for (size_t i = 1; i < n; ++i)
        s[p[i-1]-1].push_back(i);

    answer(traverse(s, 0, a));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), p(n-1);
    std::cin >> a >> p;

    solve(a, p);
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
