#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::vector<int>& b)
{
    const size_t n = b.size();

    unsigned f[2] = {};
    for (const int x : b)
        ++f[x > 0];

    std::vector<unsigned> ub(n);
    for (size_t i = 0; i < n; ++i)
        ub[i] = (i < f[1] ? 1 + i : ub[i-1] - 1);

    std::vector<unsigned> lb(n);
    for (size_t i = 0; i < n; ++i)
        lb[i] = (i <= 2 * f[0] ? 1 - i % 2 : lb[i-1] + 1);

    answer(ub, lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> b(n);
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
