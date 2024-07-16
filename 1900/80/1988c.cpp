#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << separator << *it;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(integer n)
{
    std::vector<integer> s = { n };
    for (unsigned i = 0; i < 63; ++i) {
        const integer d = 1ull << i, v = n - d;
        if (v != 0 && (v | s.back()) == n)
            s.push_back(v);
    }

    answer(s);
}

void test_case()
{
    integer n;
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
