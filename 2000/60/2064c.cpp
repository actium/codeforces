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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<integer> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (a[i] > 0 ? a[i] : 0);

    integer s = 0, t = 0;
    for (size_t i = n-1; ~i != 0; --i) {
        if (a[i] < 0)
            t -= a[i];

        s = std::max(s, p[i+1] + t);
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
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
