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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[200];
    for (size_t i = 0; i < n; ++i)
        p[a[i]-1].push_back(i);

    std::vector<std::vector<unsigned>> c(200, std::vector<unsigned>(1+n));
    for (size_t i = 0; i < 200; ++i) {
        for (const size_t j : p[i])
            c[i][j+1] = 1;

        for (size_t j = 1; j <= n; ++j)
            c[i][j] += c[i][j-1];
    }

    size_t v = 0;
    for (size_t x = 0; x < 200; ++x) {
        v = std::max(v, p[x].size());

        for (size_t k = 1; 2 * k <= p[x].size(); ++k) {
            const size_t lb = p[x][k-1], ub = p[x][p[x].size()-k];

            for (size_t i = 0; i < 200; ++i)
                v = std::max(v, k + c[i][ub] - c[i][lb+1] + k);
        }
    }

    answer(v);
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
