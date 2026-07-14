#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
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
    if (n == 2)
        return no_answer();

    std::vector<integer> v(n);
    {
        integer s = 0;
        for (size_t i = 0; i < n; ++i) {
            v[i] = (i < 3 ? i + 1 : s);
            s += v[i];
        }
    }

    answer(v);
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
