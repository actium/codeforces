#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

unsigned check(std::string s, char alpha)
{
    const size_t n = s.size();

    unsigned c[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != alpha) {
            ++c[s[i]-'0'];
            s[i] = ' ';
        } else {
            alpha ^= 1;
        }
    }

    const auto d = std::max(c[0], c[1]) - std::min(c[0], c[1]);
    if (d < 2)
        return c[0] + c[1];

    if (d == 2) {
        const auto x = s.find_last_not_of(' ');
        if (x != std::string::npos && (s[x] == '0') == (c[0] < c[1]))
            return c[0] + c[1] + 1;
    }

    return oo;
}

void solve(const std::string& s)
{
    const auto c0 = check(s, '0'), c1 = check(s, '1');
    if (c0 != oo || c1 != oo)
        return answer(std::min(c0, c1));

    no_answer();
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
