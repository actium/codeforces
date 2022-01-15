#include <iostream>
#include <set>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, unsigned k)
{
    std::set<integer> s;
    for (integer d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            s.insert(d);
            s.insert(n / d);
        }
    }

    if (s.size() < k)
        return no_answer();

    auto it = s.begin();
    std::advance(it, k-1);
    answer(*it);
}

int main()
{
    integer n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    solve(n, k);

    return 0;
}
