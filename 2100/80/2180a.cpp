#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned a, unsigned b)
{
    std::vector<bool> v(l);
    while (!v[a]) {
        v[a] = true;
        a = (a + b) % l;
    }

    unsigned x = l-1;
    while (!v[x])
        --x;

    answer(x);
}

void test_case()
{
    unsigned l, a, b;
    std::cin >> l >> a >> b;

    solve(l, a, b);
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
