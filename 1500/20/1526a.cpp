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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size() / 2;

    std::sort(a.begin(), a.end());

    const char* separator = "";
    for (size_t i = 0; i < n; ++i) {
        std::cout << separator << a[i] << ' ' << a[i+n];
        separator = " ";
    }
    std::cout << '\n';
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
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
