#include <iostream>
#include <string>

constexpr unsigned M = 1'000'000'007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, unsigned x)
{
    unsigned long long n = s.length();

    for (unsigned c = 0; c++ < x; ) {
        if (s.length() < x) {
            const std::string b = s.substr(c);

            for (char i = '1'; i < s[c-1]; ++i)
                s.append(b);
        }

        n += (M + n - c) * (s[c-1] - '1');
        n %= M;
    }

    answer(n);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    std::string s;
    std::cin >> s;

    solve(s, x);
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
