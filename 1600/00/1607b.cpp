#include <iostream>

using integer = long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer x, integer n)
{
    const auto factor = (x % 2 == 0 ? 1 : -1);

    switch (n % 4) {
        case 0: return answer(x);
        case 1: return answer(x - factor * n);
        case 2: return answer(x + factor * 1);
        case 3: return answer(x + factor * (1 + n));
    }
}

void test_case()
{
    integer x, n;
    std::cin >> x >> n;

    solve(x, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
