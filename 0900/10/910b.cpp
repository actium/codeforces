#include <iostream>
#include <set>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    if (2 * a + b == n)
        return answer(2);

    std::multiset<unsigned> p = { n, n, n, n, n, n }, q = { a, a, a, a, b, b };
    while (!q.empty()) {
        const auto it = std::prev(q.end()), jt = p.lower_bound(*it);

        const unsigned x = *jt;
        p.erase(jt);
        p.insert(x - *it);

        q.erase(it);
    }

    unsigned k = 6;
    for (const unsigned x : p)
        k -= (x == n);

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}
