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

void solve(const std::vector<unsigned>& a, unsigned z)
{
    unsigned x = 0;
    for (const unsigned q : a)
        x = std::max(x, q | z);

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned z;
    std::cin >> z;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, z);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
