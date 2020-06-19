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

void solve(const std::vector<size_t>& a, const std::vector<size_t>& b)
{
    const size_t k1 = a.size();
    const size_t k2 = b.size();
    const size_t n = k1 + k2;

    answer(*std::max_element(a.cbegin(), a.cend()) > *std::max_element(b.cbegin(), b.cend()));
}

void test_case()
{
    size_t n, k1, k2;
    std::cin >> n >> k1 >> k2;

    std::vector<size_t> a(k1);
    std::cin >> a;

    std::vector<size_t> b(k2);
    std::cin >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

