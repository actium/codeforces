#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& a, const std::string& b, unsigned x, unsigned y)
{
    const size_t n = a.length();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i])
            p.push_back(i);
    }

    if (p.size() % 2 == 1)
        return no_answer();

    if (p.size() == 2 && p[1] == p[0] + 1)
        return answer(std::min(x, 2 * y));

    answer(p.size() / 2ull * y);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b, x, y);
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
