#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t m)
{
    if (n == 1)
        return answer(0);

    if (n == 2)
        return answer(m);

    answer(2 * m);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

