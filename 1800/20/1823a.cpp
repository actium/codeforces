#include <iostream>
#include <vector>

void answer(const std::vector<int>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k)
{
    for (unsigned i = 0; i <= n; ++i) {
        const unsigned p = i * (i - 1) / 2, q = (n - i) * (n - i - 1) / 2;
        if (p + q == k) {
            std::vector<int> v(i, -1);
            v.insert(v.end(), n - i, 1);
            return answer(v);
        }
    }

    no_answer();
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
