#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }

    std::cout << '\n';
}

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> a;

    for (unsigned i = (k + 1) / 2; i < k; ++i)
        a.push_back(i);

    for (unsigned i = k + 1; i <= n; ++i)
        a.push_back(i);

    answer(a);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
