#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    integer s = 0;
    for (const unsigned x : a)
        s += x;

    integer t = 0;
    for (const unsigned x : b)
        t += x;

    if (s == t)
        return answer("Draw");

    answer(s > t ? "Tsondu" : "Tenzing");
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

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
