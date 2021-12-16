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

void solve(std::vector<unsigned>& a, unsigned h)
{
    std::sort(a.rbegin(), a.rend());

    const unsigned p = a[0] + a[1];
    const unsigned k = h / p;

    if (k * p == h)
        return answer(2 * k);

    answer(2 * k + 1 + (h - k * p > a[0]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned h;
    std::cin >> h;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
