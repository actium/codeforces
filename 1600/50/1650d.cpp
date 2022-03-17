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

    std::vector<unsigned> d(n);
    for (unsigned i = n; i > 0; --i) {
        const unsigned x = std::find(a.begin(), a.end(), i) - a.begin() + 1;
        if (x < i) {
            d[i-1] = x;
            std::rotate(a.begin(), a.begin() + x, a.begin() + i);
        }
    }

    answer(d);
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
