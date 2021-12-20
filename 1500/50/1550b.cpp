#include <algorithm>
#include <iostream>
#include <string>

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, int a, int b)
{
    const int n = s.length();
    if (b >= 0)
        return answer((a + b) * n);

    const int k = std::unique(s.begin(), s.end()) - s.begin();
    answer(a * n + b * (k / 2 + 1));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
