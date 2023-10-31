#include <iostream>
#include <string>

void answer(const std::pair<size_t, size_t>& x, const std::pair<size_t, size_t>& y)
{
    std::cout << 1 + x.first << ' ' << 1 + x.second << ' ' << 1 + y.first << ' ' << 1 + y.second << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const size_t x = s.find('0');
    if (x == std::string::npos)
        return answer(std::make_pair(0, n - 2), std::make_pair(1, n - 1));

    if (x < n / 2)
        return answer(std::make_pair(x, n - 1), std::make_pair(x + 1, n - 1));

    answer(std::make_pair(0, x), std::make_pair(0, x - 1));
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
