#include <iostream>
#include <vector>

void search(unsigned u, unsigned v, std::vector<unsigned>& p)
{
    if (p[v] != 0)
        return;

    std::cout << '?' << ' ' << u << ' ' << v << std::endl;

    unsigned x;
    std::cin >> x;

    if (x == u) {
        p[v] = u;
    } else {
        search(u, x, p);
        search(x, v, p);
    }
}

void solve(unsigned n)
{
    std::vector<unsigned> p(1+n);
    for (size_t i = 2; i <= n; ++i)
        search(1, i, p);

    std::cout << '!';
    for (size_t i = 2; i <= n; ++i)
        std::cout << ' ' << p[i] << ' ' << i;

    std::cout << std::endl;
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
