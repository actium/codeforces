#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t /*k*/)
{
    std::string s;
    for (size_t i = 0; i < n; ++i)
        s.push_back('a' + i % 3);

    answer(s);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

