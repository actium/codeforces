#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

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

    const auto p = [](unsigned x) {
        constexpr unsigned t[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

        size_t i = 0;
        while (x % t[i] != 0)
            ++i;

        return i;
    };

    unsigned t[11] = {}, m = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t j = p(a[i]);
        if (t[j] == 0)
            t[j] = ++m;
    }

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = t[p(a[i])];

    answer(m, c);
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
