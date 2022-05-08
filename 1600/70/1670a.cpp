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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    for (size_t i = 0, j = 0; i < n; ++i) {
        if (a[i] < 0) {
            a[j] = -a[j];
            a[i] = -a[i];
            ++j;
        }
    }

    answer(std::is_sorted(a.cbegin(), a.cend()));
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
