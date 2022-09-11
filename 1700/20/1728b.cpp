#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = 1 + i;

    for (size_t i = n % 2; i + 2 < n; i += 2)
        std::swap(p[i], p[i+1]);

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
