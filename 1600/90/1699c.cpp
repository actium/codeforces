#include <iostream>
#include <set>
#include <vector>

constexpr unsigned M = 1'000'000'007;

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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]] = i;

    unsigned q = 1;
    {
        std::set<unsigned> v;
        v.insert(0);
        for (size_t lb = x[0], ub = x[0], t = 1, k = 0; ub - lb + 1 != n; ) {
            while (lb > x[t]) {
                v.insert(p[--lb]);
                ++k;
            }
            while (ub < x[t]) {
                v.insert(p[++ub]);
                ++k;
            }

            --k;

            while (v.count(++t) != 0)
                q = 1ull * q * k-- % M;
        }
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

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
