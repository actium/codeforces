#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned k)
{
    switch (k) {
        case 1:
            return answer(1);
        case 2:
            return answer(m > n ? n + (m - n) / n : m);
        case 3:
            return answer(m > n ? m - n - (m - n) / n : 0);
    }

    answer(0);
}

void test_case()
{
    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
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
