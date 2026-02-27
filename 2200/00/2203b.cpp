#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string x)
{
    const size_t n = x.length();

    std::sort(std::next(x.begin()), x.end());

    std::pair<size_t, unsigned> c1 = { 0, 0 };
    while (c1.first < n && c1.second + x[c1.first] - '0' < 10)
        c1.second += x[c1.first++] - '0';

    std::pair<size_t, unsigned> c2 = { 1, 1 };
    while (c2.first < n && c2.second + x[c2.first] - '0' < 10)
        c2.second += x[c2.first++] - '0';

    answer(std::min(n - c1.first, 1 + n - c2.first));
}

void test_case()
{
    std::string x;
    std::cin >> x;

    solve(x);
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
