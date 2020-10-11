#include <iostream>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned n)
{
    for (unsigned i = 0; i * 3 <= n; ++i) {
        for (unsigned j = 0; i * 3 + j * 5 <= n; ++j) {
            const unsigned k = n - i * 3 - j * 5;
            if (k % 7 == 0)
                return answer(i, j, k / 7);
        }
    }

    no_answer();
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

