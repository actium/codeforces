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

void solve(unsigned n, unsigned k)
{
    if (k == n - 1)
        return no_answer();

    std::string s;
    s.append((k + 0) / 2 + 1, '0');
    s.append((k + 1) / 2 + 1, '1');
    while (s.size() < n)
        s.push_back(s.back() ^ 1);

    answer(s);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
