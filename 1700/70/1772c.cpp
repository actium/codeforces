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

void solve(unsigned k, unsigned n)
{
    std::vector<unsigned> a(k);
    for (unsigned i = 0, x = 1; i < k; ++i) {
        a[i] = x;

        if (a[i] + k - 1 > n)
            ++x;
        else
            x += i + 1;
    }

    answer(a);
}

void test_case()
{
    unsigned k, n;
    std::cin >> k >> n;

    solve(k, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
