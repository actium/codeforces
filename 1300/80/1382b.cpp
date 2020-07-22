#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    constexpr const char* s[2] = { "First", "Second" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const unsigned n = a.size();

    unsigned p = 0;
    for (size_t i = 0; i < n-1 && a[i] == 1; ++i)
        ++p;

    answer(p % 2);
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

