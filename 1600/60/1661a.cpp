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

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size();

    integer s = 0;
    for (size_t i = 1; i < n; ++i) {
        s += std::abs(std::max(a[i-1], b[i-1]) - std::max(a[i], b[i]));
        s += std::abs(std::min(a[i-1], b[i-1]) - std::min(a[i], b[i]));
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
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
