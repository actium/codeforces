#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(char x)
{
    std::cout << x;
}

void solve(std::string& s, integer p)
{
    const size_t n = s.length();

    size_t k = 0;
    while (p > n - k)
        p -= n - k++;

    std::string t;
    for (const char c : s) {
        while (k != 0 && !t.empty() && c < t.back()) {
            t.pop_back();
            --k;
        }
        t.push_back(c);
    }

    answer(t[p-1]);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    integer p;
    std::cin >> p;

    solve(s, p);
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
