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
    if (n < 5)
        return no_answer();

    std::vector<unsigned> p;
    {
        for (unsigned i = 1; i <= n; i += 2) {
            if (i != 5)
                p.push_back(i);
        }

        p.push_back(5);
        p.push_back(4);

        for (unsigned i = 2; i <= n; i += 2) {
            if (i != 4)
                p.push_back(i);
        }
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
