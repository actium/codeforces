#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    s.erase(std::unique(s.begin(), s.end()), s.end());

    const size_t k = s.length();
    if (k == 1 || k == 2 && s[0] == '1')
        return answer(k);

    answer(k - 1);
}

void test_case()
{
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
