#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned m, unsigned k)
{
    char p = '0', q = '1';
    if (m > n) {
        std::swap(n, m);
        std::swap(p, q);
    }

    if (n - k > m)
        return no_answer();

    std::string s(k, p);
    n -= k;
    while (m != 0) {
        s.push_back(q);
        --m;

        std::swap(n, m);
        std::swap(p, q);
    }
    s.append(n, p);

    answer(s);
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
