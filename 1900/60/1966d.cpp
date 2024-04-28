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

void solve(unsigned n, unsigned k)
{
    const unsigned c = __builtin_clz(1) - __builtin_clz(k), b = 1 << c;

    std::vector<unsigned> s;
    for (unsigned i = 0; i < 20; ++i) {
        if (i != c)
            s.push_back(1 << i);
    }

    s.push_back(k - b);
    s.push_back(k + 1);
    s.push_back(k + b + 1);

    answer(s);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
