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

void solve(const std::vector<unsigned>& a, unsigned x, unsigned y)
{
    integer s = 0;
    for (const unsigned v : a)
        s += v / x * y;

    integer best = 0;
    for (const unsigned v : a)
        best = std::max(best, s - v / x * y + v);

    answer(best);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x, y);
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
