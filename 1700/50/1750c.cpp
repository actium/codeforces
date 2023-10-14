#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << "YES" << '\n';

    std::cout << v.size() << '\n';
    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1 + x.first << ' ' << 1 + x.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length();

    std::vector<std::pair<size_t, size_t>> c;

    unsigned x = b[0];
    for (size_t i = 1; i < n; ++i) {
        if ((a[i] == a[0]) != (b[i] == b[0]))
            return no_answer();

        if (a[i] != a[0]) {
            c.emplace_back(i, i);
            x ^= 1;
        }
    }

    if (a[0] != x)
        c.emplace_back(0, n - 1);

    if (x == '1') {
        c.emplace_back(0, 0);
        c.emplace_back(1, n - 1);
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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