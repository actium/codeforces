#include <iostream>
#include <set>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    std::multiset<unsigned> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);

    for (unsigned i = 0; i < 5; ++i) {
        s.insert(*s.begin() + 1);
        s.erase(s.begin());
    }

    unsigned k = 1;
    for (const unsigned x : s)
        k *= x;

    answer(k);
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
