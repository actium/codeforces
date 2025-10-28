#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned, unsigned r)
{
    const size_t n = r + 1;

    std::vector<unsigned> a(n);
    {
        std::vector<bool> v(n);
        for (unsigned i = r; i != 0; --i) {
            if (!v[i]) {
                const unsigned x = (1 << 32 - __builtin_clz(i)) - 1;

                a[i] = x ^ i;
                v[a[i]] = true;

                a[a[i]] = i;
                v[i] = true;
            }
        }
    }

    answer(r * (r + 1ull), a);
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
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
