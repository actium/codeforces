#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << separator << *it;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned x)
{
    std::vector<unsigned> a = { 1, 2 };
    for (unsigned d = 1; a.back() != x; a.push_back(a.back() + d))
        for (d *= 2; a.back() + d > x; d /= 2);

    answer(a);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    solve(x);
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
