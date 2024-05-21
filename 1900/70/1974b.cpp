#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& b)
{
    std::string t = b;
    std::sort(t.begin(), t.end());

    char x[256];
    for (size_t i = 0, j = std::unique(t.begin(), t.end()) - t.begin(); i < j--; ++i) {
        x[t[i]] = t[j];
        x[t[j]] = t[i];
    }

    for (auto it = b.begin(); it != b.end(); ++it)
        *it = x[*it];

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string b;
    std::cin >> b;

    solve(b);
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
