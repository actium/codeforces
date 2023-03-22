#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<unsigned> c;
    c.insert(c.end(), a.begin(), a.end());
    c.insert(c.end(), b.begin(), std::prev(b.end()));

    std::sort(c.begin(), c.end(), std::greater<unsigned>());

    integer s = b.back();
    for (size_t i = 0; i + 1 < n; ++i)
        s += c[i];

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
