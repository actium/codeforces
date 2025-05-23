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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& g)
{
    const size_t n = g.size();

    std::vector<unsigned> p(2 * n);
    for (size_t i = 0; i < n; ++i) {
        p[1+i] = g[0][i];
        p[n+i] = g[n-1][i];
    }

    for (unsigned i = 1; i <= 2 * n; ++i)
        p[0] ^= p[i-1] ^ i;

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> g(n, std::vector<unsigned>(n));
    std::cin >> g;

    solve(g);
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
