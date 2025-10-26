#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

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

void solve(unsigned a, unsigned b)
{
    if (__builtin_clz(a) > __builtin_clz(b))
        return no_answer();

    std::vector<unsigned> ops;
    if ((a ^ b) > a) {
        const unsigned x = (1 << 32 - __builtin_clz(b)) - 1;
        ops.push_back(x);
        a ^= x;
    }
    ops.push_back(a ^ b);

    answer(ops);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
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
