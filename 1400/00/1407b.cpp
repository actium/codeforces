#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::swap(*std::max_element(a.begin(), a.end()), *a.begin());

    unsigned d = a.front();
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = i; j < n; ++j) {
            if (std::gcd(d, a[j]) > std::gcd(d, a[i]))
                std::swap(a[i], a[j]);
        }
        d = std::gcd(d, a[i]);
    }

    answer(a);
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

