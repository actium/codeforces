#include <algorithm>
#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << "NO\n";
}

void answer(const std::array<unsigned, 3>& v)
{
    std::cout << "YES\n";
    std::cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
}

void solve(std::array<unsigned, 3>& a)
{
    std::sort(a.begin(), a.end());

    if (a[1] != a[2])
        return no_answer();

    a[1] = a[0];
    answer(a);
}

void test_case()
{
    std::array<unsigned, 3> a;
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

