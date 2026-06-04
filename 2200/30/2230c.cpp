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

void solve(const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    size_t x = 0;
    while (x < n && c[x] == 1)
        ++x;

    integer t = 0, k = (x == n-1);
    for (size_t i = x; i < n; ++i) {
        t += c[i];
        k += (c[i] - 2) / 2;
    }
    t += std::min<integer>(x, k);

    answer(t > 2 ? t : 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);
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
