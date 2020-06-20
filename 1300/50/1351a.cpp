#include <bits/stdc++.h>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(int a, int b)
{
   answer(a + b);
}

void test_case()
{
    int a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

