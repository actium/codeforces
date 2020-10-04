#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer l1, integer r1, integer l2, integer r2, integer k)
{
    const integer b = std::max(l1, l2);
    const integer e = std::min(r1, r2);

    if (b > e)
        return answer(0);

    answer(e - b + (k < b || k > e));
}

int main()
{
    integer l1, r1, l2, r2, k;
    std::cin >> l1 >> r1 >> l2 >> r2 >> k;

    solve(l1, r1, l2, r2, k);

    return 0;
}

