#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    integer k = 0;

    const auto d = [](integer q) {
        return q * (q + 1) / 2;
    };

    size_t b = 0, c = 0, q = 0;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == '?') {
            ++q;
            continue;
        }
        if (s[c] == '?' || s[i] == s[c] ^ (i - c) % 2) {
            c = i;
            q = 0;
            continue;
        }

        k += d(i - b);

        if (s[i-1] == '?') {
            k -= d(q);
            b = i - q;
        } else {
            b = i;
        }

        c = i;
        q = 0;
    }

    k += d(n - b);

    answer(k);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
