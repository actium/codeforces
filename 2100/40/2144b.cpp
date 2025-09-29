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

    std::vector<size_t> z, x(1+n, n);
    for (size_t i = 0; i < n; ++i) {
        if (p[i] == 0)
            z.push_back(i);
        else
            x[p[i]] = i;
    }

    for (unsigned i = 1; i <= n; ++i) {
        if (x[i] == n) {
            p[z.back()] = i;
            z.pop_back();
        }
    }

    size_t lb = 0;
    while (lb < n && p[lb] == lb+1)
        ++lb;

    size_t ub = n;
    while (ub > lb && p[ub-1] == ub)
        --ub;

    answer(ub - lb);
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
