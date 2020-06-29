#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    answer(n);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


