#include <iostream>
#include <vector>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> f;
    for (unsigned x = 2; x * x <= n && f.size() < 2; ++x) {
        if (n % x == 0) {
            f.push_back(x);
            n /= x;
        }
    }

    if (f.size() < 2 || n == f[0] || n == f[1] || n == 1)
        return no_answer();

    answer(f[0], f[1], n);
}

void test_case()
{
    unsigned n;
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

