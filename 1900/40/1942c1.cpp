#include <algorithm>
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

void solve(unsigned n, std::vector<unsigned>& p)
{
    const size_t m = p.size();

    std::sort(p.begin(), p.end());

    unsigned k = m - 2;
    for (size_t i = 1; i < m; ++i)
        k += (p[i] - p[i-1] == 2);

    k += (p[0] + n - p[m-1] == 2);

    answer(k);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    size_t x, y;
    std::cin >> x >> y;

    std::vector<unsigned> p(x);
    std::cin >> p;

    solve(n, p);
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
