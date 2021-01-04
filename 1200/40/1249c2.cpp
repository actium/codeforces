#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    std::vector<integer> t = { 1 };
    for (integer x = 1; x < n; x *= 3)
        t.push_back(x * 3);

    const size_t k = t.size();

    std::vector<integer> p = t;
    for (size_t i = 1; i < k; ++i)
        p[i] += p[i-1];

    integer m = 0;
    for (size_t i = k-1; m < n; m += t[i]) {
        while (i > 0 && m + t[i] >= n)
            --i;

        if (m + p[i] < n)
            ++i;
    }

    answer(m);
}

void test_case()
{
    integer n;
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

