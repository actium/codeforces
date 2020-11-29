#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

unsigned f(const std::vector<unsigned>& c, size_t k, unsigned x)
{
    const size_t n = c.size();

    unsigned p = 0;
    for (size_t i = 0; i < n; ++i) {
        if (c[i] != x) {
            ++p;
            i += k-1;
        }
    }
    return p;
}

void solve(const std::vector<unsigned>& c, size_t k)
{
    std::set<unsigned> a(c.cbegin(), c.cend());

    unsigned t = ~0u;
    for (const unsigned x : a)
        t = std::min(t, f(c, k, x));

    answer(t);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

