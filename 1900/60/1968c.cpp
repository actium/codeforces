#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& x)
{
    const size_t n = x.size() + 1;

    std::vector<unsigned> a(n, 501);
    for (size_t i = 1; i < n; ++i)
        a[i] = a[i-1] + x[i-1];

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n-1);
    std::cin >> x;

    solve(x);
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
