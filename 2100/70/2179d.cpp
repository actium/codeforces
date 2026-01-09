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

void solve(unsigned n)
{
    const size_t k = 1 << n;

    std::vector<unsigned> p;
    p.reserve(k);

    std::vector<bool> v(k);
    for (unsigned i = n; ~i != 0; --i) {
        for (unsigned j = 0, m = 1 << (n - i); j < m; ++j) {
            const unsigned x = j << i | (1 << i) - 1;
            if (!v[x]) {
                p.push_back(x);
                v[x] = true;
            }
        }
    }

    answer(p);
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
