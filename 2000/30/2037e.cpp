#include <iostream>
#include <string>
#include <vector>

unsigned query(unsigned l, unsigned r)
{
    std::cout << '?' << ' ' << l << ' ' << r << std::endl;

    unsigned v;
    std::cin >> v;
    return v;
}

void answer(const std::string& x)
{
    std::cout << '!' << ' ' << x << std::endl;
}

void solve(unsigned n)
{
    std::vector<unsigned> c(n);
    for (unsigned i = 2; i <= n; ++i)
        c[i-1] = query(1, i);

    if (c[n-1] == 0)
        return answer("IMPOSSIBLE");

    size_t x = 0;
    while (c[x] == 0)
        ++x;

    std::string s(n, '1');
    for (size_t i = 1; i <= c[x]; ++i)
        s[x-i] = '0';

    for (size_t i = x+1; i < n; ++i) {
        if (c[i] == c[i-1])
            s[i] = '0';
    }

    answer(s);
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
