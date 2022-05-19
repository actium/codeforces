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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& x)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i) {
        ps[i+1] = ps[i] + a[i];
    }

    for (const unsigned q : x) {
        const auto it = std::lower_bound(ps.cbegin(), ps.cend(), q);
        if (it == ps.cend())
            no_answer();
        else
            answer(std::distance(ps.cbegin(), it));
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> x(q);
    std::cin >> x;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

