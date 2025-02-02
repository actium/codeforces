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

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned k = 0;
        for (size_t j = 0; j <= i; ++j)
            k += (g[i][j] == '0');
        for (size_t j = i+1; j < n; ++j)
            k += (g[i][j] == '1');

        p[n-k] = 1 + i;
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> g(n);
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
