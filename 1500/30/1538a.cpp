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

void solve(const std::vector<unsigned>& a)
{
    const auto r = std::minmax_element(a.cbegin(), a.cend());

    const size_t d1 = std::distance(a.cbegin(), r.first) + 1;
    const size_t d2 = std::distance(r.first, a.cend());
    const size_t d3 = std::distance(a.cbegin(), r.second) + 1;
    const size_t d4 = std::distance(r.second, a.cend());

    const size_t c1 = std::max(d1, d3);
    const size_t c2 = std::max(d2, d4);
    const size_t c3 = d1 + d4 - (r.first == r.second);
    const size_t c4 = d2 + d3 - (r.first == r.second);

    answer(std::min({ c1, c2, c3, c4 }));
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
