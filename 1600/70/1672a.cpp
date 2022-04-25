#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    constexpr const char* s[2] = { "maomao90", "errorgorn" };
    std::cout << s[x] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned s = 0;
    for (const unsigned x : a)
        s += x - 1;

    answer(s % 2);
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
