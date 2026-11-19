#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (char c = 'z'; c > 'a'; --c) {
        unsigned d = 0;
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == c && s[n-1-i] != c) {
                --s[i];
                d = 1;
            }
        }
        k += d;
    }

    answer(k);
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
