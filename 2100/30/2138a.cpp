#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned k, integer x)
{
    std::vector<unsigned> q;
    for (unsigned i = 0; x != 0; ++i) {
        const integer mask = 1ull << k - i;
        q.push_back((x & mask) != 0);
        x &= ~mask;
    }

    answer(std::vector<unsigned>(q.rbegin() + 1, q.rend()));
}

void test_case()
{
    unsigned k;
    std::cin >> k;

    integer x;
    std::cin >> x;

    solve(k, x);
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
