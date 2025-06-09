#include <iostream>

using integer = long long;

constexpr integer B = 1000000000000000000;

void query_digit()
{
    std::cout << "digit" << std::endl;

    unsigned r;
    std::cin >> r;
}

bool query_add(integer y)
{
    std::cout << "add " << y << std::endl;

    unsigned r;
    std::cin >> r;
    return r == 1;
}

void answer()
{
    std::cout << "!" << std::endl;

    int r;
    std::cin >> r;
}

void solve(unsigned n)
{
    query_digit();
    query_digit();

    query_add(-8);
    query_add(-4);
    query_add(-2);
    query_add(-1);

    query_add(n - 1);

    answer();
}

void test_case()
{
    unsigned n;
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
