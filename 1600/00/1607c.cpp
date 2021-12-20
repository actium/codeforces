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

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    int x = a.front();
    for (size_t i = 1; i < n; ++i)
        x = std::max(x, a[i] - a[i-1]);

    answer(x);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
