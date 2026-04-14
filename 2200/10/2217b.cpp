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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& p)
{
    const size_t x = p[0] - 1;

    std::vector<unsigned> b;
    b.push_back(a[x]);
    b.insert(b.end(), a.begin(), a.begin() + x);
    b.erase(std::unique(b.begin(), b.end()), b.end());

    std::vector<unsigned> c;
    c.insert(c.end(), a.begin() + x + 1, a.end());
    c.push_back(a[x]);
    c.erase(std::unique(c.begin(), c.end()), c.end());

    answer(std::max(b.size(), c.size()) & ~1u);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n), p(k);
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
