#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t m, size_t k)
{
    const std::string p(m, '0');

    unsigned q = 0;
    for (size_t x = s.find(p); x != std::string::npos; x = s.find(p, x + m + k - 1))
        ++q;

    answer(q);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::string s;
    std::cin >> s;

    solve(s, m, k);
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
