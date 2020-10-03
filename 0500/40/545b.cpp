#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    std::string p = s;
    unsigned x = 1;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            p[i] ^= x;
            x ^= 1;
        }
    }

    answer(x == 1 ? p : "impossible");
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

