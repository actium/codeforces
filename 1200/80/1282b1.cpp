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

void solve(std::vector<unsigned>& a, unsigned p, unsigned k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    unsigned c1 = p, q1 = 0;
    for (size_t i = 0; i < n && a[i] <= c1; i += 2) {
        c1 -= a[i];
        q1 += 2;
    }
    q1 -= (q1 > 0);

    unsigned c2 = p, q2 = 0;
    for (size_t i = 1; i < n && a[i] <= c2; i += 2) {
        c2 -= a[i];
        q2 += 2;
    }

    answer(std::max(q1, q2));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned p, k;
    std::cin >> p >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, p, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
