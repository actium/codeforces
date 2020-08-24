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

void solve(std::vector<int>& a, unsigned long long k)
{
    for (unsigned i = 0, n = 2 - k % 2; i < n; ++i) {
        const int max = *std::max_element(a.cbegin(), a.cend());
        for (int& x : a)
            x = max - x;
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned long long k;
    std::cin >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

