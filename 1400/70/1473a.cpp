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

void solve(std::vector<unsigned>& a, unsigned d)
{
    std::sort(a.begin(), a.end());

    answer(a.back() <= d || a[0] + a[1] <= d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

