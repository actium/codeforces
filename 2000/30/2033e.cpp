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

void solve(std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(n);
    for (size_t i = 1; i < n; ++i)
        x[p[i]] = i;

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (p[i] != i && p[p[i]] != i) {
            const size_t j = p[p[i]];
            std::swap(x[i], x[j]);
            std::swap(p[x[i]], p[x[j]]);
            ++k;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(1+n);
    for (size_t i = 1; i <= n; ++i)
        std::cin >> p[i];

    solve(p);
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
