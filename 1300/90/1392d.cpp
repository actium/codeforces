#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    const size_t x = s.find(s[0]^'R'^'L');
    if (x == std::string::npos)
        return answer((n + 2) / 3);

    s = s.substr(x) + s.substr(0, x);

    unsigned k = 0, c = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) {
            k += c / 3;
            c = 0;
        }
        ++c;
    }

    answer(k + c / 3);
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
