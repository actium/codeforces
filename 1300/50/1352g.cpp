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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    if (n < 4)
        return no_answer();

    std::vector<unsigned> p(n);
    for (size_t i = 0, x = (n - 1) | 1; i < n; ++i) {
        p[i] = x;

        if (x == 1) {
            p[++i] = 4;
            p[++i] = 2;
            x = 4;
        }

        if (x % 2 == 0)
            x += 2;
        else
            x -= 2;
    }

    answer(p);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
