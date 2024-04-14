#include <iostream>
#include <vector>

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(unsigned u, const std::vector<std::vector<unsigned>>& v)
{
    std::cout << u << ' ' << v.size() << '\n';

    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> p(2 + n);
    for (unsigned i = 1; i <= n; ++i)
        p[i+1] = i;

    unsigned s = 0;
    for (unsigned i = 1; i <= n; ++i)
        s += i * (2 * i - 1);

    std::vector<std::vector<unsigned>> ops(2 * n - 1);
    for (size_t i = 0; i < 2 * n - 1; ++i) {
        ops[i] = p;
        ops[i][0] = 1 + i % 2;
        ops[i][1] = (2 * n - i) / 2;
    }

    answer(s, ops);
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
