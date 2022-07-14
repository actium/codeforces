#include <array>
#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::array<std::array<unsigned, 2>, 2>& a)
{
    const unsigned k = a[0][0] + a[0][1] + a[1][0] + a[1][1];
    switch (k) {
        case 0: return answer(0);
        case 4: return answer(2);
        default: return answer(1);
    }
}

void test_case()
{
    std::array<std::array<unsigned, 2>, 2> a;
    std::cin >> a[0][0] >> a[0][1];
    std::cin >> a[1][0] >> a[1][1];

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
