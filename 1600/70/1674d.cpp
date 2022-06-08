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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    for (size_t i = 1 + n % 2; i < n; i += 2) {
        if (a[i] < a[i-1])
            std::swap(a[i], a[i-1]);
    }

    answer(std::is_sorted(a.cbegin(), a.cend()));
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
