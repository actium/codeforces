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

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> b(n);
    for (size_t i = 0; i < n; ++i)
        b[i] = i;

    const size_t x = std::max_element(a.begin(), a.end()) - a.begin();
    std::swap(b[0], b[x]);

    unsigned long long s = 0;
    for (size_t i = 0; i < x; ++i) {
        s += a[i];
        b[i] = i + (s < a[x]);
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> a(n);
    std::cin >> a;

    a[0] += c;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
