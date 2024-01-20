#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Recipe {
    std::vector<unsigned> ingredients;
};

std::istream& operator >>(std::istream& input, Recipe& r)
{
    size_t m;
    std::cin >> m;

    r.ingredients.resize(m);
    return input >> r.ingredients;
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

unsigned evaluate(std::vector<int>& d, size_t u, const std::vector<unsigned>& c, const std::vector<Recipe>& r)
{
    using integer = unsigned long long;

    if (d[u] == -1) {
        integer v = r[u].ingredients.empty() ? ~0u : 0;
        for (const unsigned x : r[u].ingredients)
            v += evaluate(d, x-1, c, r);

        d[u] = std::min<integer>(v, c[u]);
    }
    return d[u];
}

void solve(const std::vector<unsigned>& c, const std::vector<unsigned>& p, const std::vector<Recipe>& r)
{
    const size_t n = c.size();

    std::vector<int> d(n, -1);
    for (const unsigned x : p)
        d[x-1] = 0;

    for (size_t i = 0; i < n; ++i)
        evaluate(d, i, c, r);

    answer(d);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> c(n), p(k);
    std::cin >> c >> p;

    std::vector<Recipe> r(n);
    std::cin >> r;

    solve(c, p, r);
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
