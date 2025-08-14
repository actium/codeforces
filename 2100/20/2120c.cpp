#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<unsigned>& v)
{
    std::cout << v[0] << '\n';

    for (size_t i = 1; i < v.size(); ++i)
        std::cout << v[i-1] << ' ' << v[i] << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, integer m)
{
    if (m < n || 2 * m > n * (n + 1))
        return no_answer();

    std::vector<unsigned> p, q;
    {
        m -= n - 1;

        for (unsigned x = n; x != 0; --x) {
            if (m >= x) {
                p.push_back(x);
                m -= x - 1;
            } else {
                q.push_back(x);
            }
        }

        p.insert(p.end(), q.begin(), q.end());
    }

    answer(p);
}

void test_case()
{
    integer n, m;
    std::cin >> n >> m;

    solve(n, m);
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
