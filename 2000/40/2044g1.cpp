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

unsigned traverse(const std::vector<unsigned>& r, size_t u, std::vector<unsigned>& s)
{
    const size_t n = r.size();

    if (s[u] == 0) {
        s[u] = 1;

        const unsigned t = traverse(r, r[u]-1, s);
        if (t != n) {
            s[u] = 3;
            return t == u ? n : t;
        }

        s[u] = 2;
    }
    return s[u] == 1 ? u : n;
}

unsigned distance(const std::vector<unsigned>& r, const std::vector<unsigned>& s, size_t u, std::vector<unsigned>& d)
{
    if (s[u] == 3)
        return 0;

    if (d[u] == 0)
        d[u] = distance(r, s, r[u]-1, d) + 1;

    return d[u];
}

void solve(const std::vector<unsigned>& r)
{
    const size_t n = r.size();

    std::vector<unsigned> s(n);
    for (size_t i = 0; i < n; ++i)
        traverse(r, i, s);

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i)
        d[i] = distance(r, s, i, d);

    unsigned x = 0;
    for (size_t i = 0; i < n; ++i)
        x = std::max(x, d[i]);

    answer(x + 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> r(n);
    std::cin >> r;

    solve(r);
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
