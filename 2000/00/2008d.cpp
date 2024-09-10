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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void paint(const std::vector<unsigned>& p, size_t u, unsigned k, std::vector<unsigned>& c)
{
    c[u] = k;

    const size_t v = p[u] - 1;
    if (c[v] == 0)
        paint(p, v, k, c);
}

void solve(const std::vector<unsigned>& p, const std::string& s)
{
    const size_t n = p.size();

    std::vector<unsigned> c(n);
    for (size_t i = 0, k = 0; i < n; ++i) {
        if (c[i] == 0)
            paint(p, i, ++k, c);
    }

    std::vector<unsigned> f(1+n);
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            ++f[c[i]];
    }

    std::vector<unsigned> v(n);
    for (size_t i = 0; i < n; ++i)
        v[i] = f[c[i]];

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::string s;
    std::cin >> s;

    solve(p, s);
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
