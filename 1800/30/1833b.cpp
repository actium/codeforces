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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a, std::vector<int>& b)
{
    const size_t n = a.size();

    std::vector<std::pair<int, size_t>> x(n);
    for (size_t i = 0; i < n; ++i) {
        x[i].first = a[i];
        x[i].second = i;
    }

    std::sort(x.begin(), x.end());
    std::sort(b.begin(), b.end());

    std::vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        v[x[i].second] = b[i];

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

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
