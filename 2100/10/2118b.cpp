#include <iostream>
#include <vector>

struct Operation {
    unsigned r;
    unsigned b;
    unsigned e;
};

void answer(const std::vector<Operation>& v)
{
    std::cout << v.size() << '\n';

    for (const Operation& x : v)
        std::cout << x.r << ' ' << x.b << ' ' << x.e << '\n';
}

void solve(unsigned n)
{
    std::vector<Operation> ops;
    ops.push_back({ 1, 1, n });
    for (unsigned i = 2; i <= n; ++i) {
        ops.push_back({ i, 1, i-1 });
        ops.push_back({ i, i, n });
    }

    answer(ops);
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
