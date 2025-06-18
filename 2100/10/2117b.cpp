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
    {
        p[0] = 1;

        for (size_t i = 1; i < n; ++i)
            p[i] = n - i + 1;
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
