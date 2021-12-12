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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b = { a[0] };
    for (size_t i = 1; i < n; ++i) {
        if (a[i] != a[i-1])
            b.push_back(a[i]);
    }
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == a[i-1])
            b.push_back(a[i]);
    }

    answer(b);
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
