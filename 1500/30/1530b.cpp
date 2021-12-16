#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';

    std::cout << '\n';
}

void solve(unsigned h, unsigned w)
{
    std::vector<std::string> t(h, std::string(w, '0'));

    for (size_t i = 0; i < (w + 1) / 2; i += 2)
        t[0][i] = t[h-1][i] = '1';

    for (size_t i = 0; i < (w - 1) / 2; i += 2)
        t[0][w-1-i] = t[h-1][w-1-i] = '1';

    for (size_t i = 0; i < (h + 1) / 2; i += 2)
        t[i][0] = t[i][w-1] = '1';

    for (size_t i = 0; i < (h - 1) / 2; i += 2)
        t[h-1-i][0] = t[h-1-i][w-1] = '1';

    answer(t);
}

void test_case()
{
    unsigned h, w;
    std::cin >> h >> w;

    solve(h, w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
