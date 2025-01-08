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

void solve(size_t n)
{
    if (n % 2 == 1 && n < 26)
        return no_answer();

    std::vector<unsigned> p(n);
    for (size_t i = n % 2, x = 1; i < n; i += 2, ++x) {
        p[i+0] = x;
        p[i+1] = x;
    }

    if (n % 2 == 1) {
        p[0] = n + 1;
        p[9] = n + 1;
        p[10] = n + 2;
        p[25] = n + 1;
        p[26] = n + 2;
    }

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
