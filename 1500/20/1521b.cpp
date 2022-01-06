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

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::vector<unsigned>& a : v) {
        const char* separator = "";
        for (const unsigned x : a) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const size_t b = std::min_element(a.cbegin(), a.cend()) - a.cbegin();

    std::vector<std::vector<unsigned>> s;
    for (size_t i = 0; i < n; ++i) {
        if (i != b) {
            a[i] = a[b] + (i % 2 != b % 2);
            s.push_back({ 1+i, 1+b, a[i], a[b] });
        }
    }

    answer(s);
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
