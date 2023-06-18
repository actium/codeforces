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

void solve(const std::vector<int>& a, size_t k, int q)
{
    const size_t n = a.size();

    integer c = 0;
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (a[i] > q)
            j = i + 1;

        if (j + k <= i + 1)
            c += i - j + 1 - k + 1;
    }

    answer(c);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    int q;
    std::cin >> q;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k, q);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
