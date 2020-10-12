#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer l, integer r)
{
    std::vector<integer> v = { 4, 7 };
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] <= 1000000000) {
            v.push_back(v[i] * 10 + 4);
            v.push_back(v[i] * 10 + 7);
        }
    }

    integer s = 0;

    auto it = std::lower_bound(v.cbegin(), v.cend(), l);
    for (integer x = l; x <= r; x = (*it++) + 1)
        s += *it * (std::min(*it, r) - x + 1);

    answer(s);
}

int main()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}

