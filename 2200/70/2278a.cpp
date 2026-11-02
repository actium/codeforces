#include <algorithm>
#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& p, std::string& q)
{
    q += "six";

    std::sort(p.begin(), p.end());
    std::sort(q.begin(), q.end());

    answer(p == q);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string p, q;
    std::cin >> p >> q;

    solve(p, q);
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
