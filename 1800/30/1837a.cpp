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

void solve(unsigned x, unsigned k)
{
    if (x % k != 0)
        answer({x});
    else
        answer({x-1, 1});
}

void test_case()
{
    unsigned x, k;
    std::cin >> x >> k;

    solve(x, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
