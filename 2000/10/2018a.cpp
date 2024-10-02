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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<integer>& a, integer k)
{
    integer x = 0, s = 0;
    for (const integer v : a) {
        x = std::max(x, v);
        s += v;
    }

    unsigned m = a.size();
    while (m * x > s + k || (m - s % m) % m > k)
        --m;

    answer(m);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a, k);
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
