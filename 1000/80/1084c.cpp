#include <iostream>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned p = 0, q = 0, k = 0;
    for (const char c : s) {
        if (c == 'a') {
            k = (k + q + 1) % M;
            ++p;
        }
        if (c == 'b' && p != 0) {
            q = (q + p + 1LL * q * p) % M;
            p = 0;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
