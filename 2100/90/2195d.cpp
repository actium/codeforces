#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<integer>& f)
{
    const size_t n = f.size();

    const integer b = (f[0] + f[n-1]) / integer(n - 1);

    std::vector<int> a(n);
    {
        a[0] = (b + f[1] - f[0]) / 2;

        for (size_t i = 1; i < n - 1; ++i)
            a[i] = (f[i-1] - 2 * f[i] + f[i+1]) / 2;

        a[n-1] = (b - f[n-1] + f[n-2]) / 2;
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> f(n);
    std::cin >> f;

    solve(f);
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
