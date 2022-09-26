#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned c)
{
    unsigned f[100] = {};
    for (const unsigned x : a)
        ++f[x-1];

    unsigned s = 0;
    for (const unsigned x : f)
        s += std::min(x, c);    

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
