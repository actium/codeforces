#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(unsigned x, integer y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer q)
{
    const integer x = q;

    std::vector<integer> f;
    for (integer i = 2; i * i <= q; ++i) {
        while (q % i == 0) {
            f.push_back(i);
            q /= i;
        }
    }

    if (f.empty())
        return answer(1, 0);

    if (f.size() == 1)
        return answer(2);

    if (f.size() == 2 && f[0] == f[1] && q == 1)
        return answer(2);

    answer(1, f[0] * f[1]);
}

int main()
{
    integer q;
    std::cin >> q;

    solve(q);

    return 0;
}
