#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, std::string& t)
{
    const size_t n = s.length();

    unsigned q = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned d = (s[i] == '0') + (t[i] == '0');
        q += d;
        if (q < 3) {
            q = d;
        } else {
            q -= 3;
            ++k;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s[2];
    std::cin >> s[0] >> s[1];

    solve(s[0], s[1]);

    return 0;
}
