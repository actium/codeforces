#include <iostream>
#include <string>
#include <utility>
#include <vector>

size_t resolve(std::vector<size_t>& roots, size_t x)
{
    size_t root = x;
    while (root != roots[root])
        root = roots[root];

    while (roots[x] != root)
        x = std::exchange(roots[x], root);

    return root;
}

size_t merge(std::vector<size_t>& roots, size_t x, size_t y)
{
    const size_t rx = resolve(roots, x), ry = resolve(roots, y);
    if (rx != ry) {
        roots[ry] = rx;
        return 1;
    }
    return 0;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> cs(n);
    for (size_t i = 0; i < n; ++i)
        cs[i] = i;

    unsigned k = 0;

    std::vector<size_t> t = { 0 };
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == '(') {
            if (s[i-1] == ')')
                k += merge(cs, i, i-1);

            t.push_back(i);
        } else {
            k += merge(cs, i, t.back());
            t.pop_back();
        }
    }

    answer(n - k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
