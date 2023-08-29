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

void solve(size_t n, std::vector<int>& b)
{
    std::sort(b.begin(), b.end());

    b.push_back(b.back());

    std::vector<int> a(n);
    for (size_t i = 0, j = 0; i < n; ++i, j += n - i)
        a[i] = b[j];

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> b(n * (n - 1) / 2);
    std::cin >> b;

    solve(n, b);
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
