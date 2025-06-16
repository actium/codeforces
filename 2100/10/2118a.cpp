#include <iostream>
#include <string>

void answer(const std::string& s)
{
    std::cout << s << '\n';
}

void solve(size_t n, size_t k)
{
    answer(std::string(k, '1') + std::string(n-k, '0'));
}

void test_case()
{
    size_t n, k;
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
