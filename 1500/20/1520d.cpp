#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i)
        a[i] -= i;

    std::sort(a.begin(), a.end());

    integer k = 0;
    for (size_t i = 0, j = 1; j < n; ++j) {
        if (a[j] == a[i])
            k += j - i;
        else
            i = j;
    }

    answer(k);
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

