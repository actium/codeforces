#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned l, unsigned r, unsigned s)
{
    const unsigned k = r - l + 1;

    if (k * (k + 1) / 2 > s || (2 * n - k + 1) * k / 2 < s)
        return no_answer();

    unsigned x = 1;
    while ((2 * x + k - 1) * k / 2 < s)
        ++x;

    std::vector<unsigned> p(n);
    {
        unsigned d = (2 * x + k - 1) * k / 2 - s;
        for (size_t i = 0; i < k; ++i) {
            if (x > d) {
                p[l-1+i] = x + i - d;
                d = 0;
            } else {
                p[l-1+i] = 1 + i;
                d -= x - 1;
            }
        }
    }

    std::vector<bool> v(1 + n);
    for (const unsigned e : p)
        v[e] = true;

    for (size_t i = 0, j = 0; i < n; ++i) {
        if (p[i] == 0) {
            while (v[j])
                ++j;

            p[i] = j++;
        }
    }

    answer(p);
}

void test_case()
{
    unsigned n, l, r, s;
    std::cin >> n >> l >> r >> s;

    solve(n, l, r, s);
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
