#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    constexpr char t[2] = { 'b', 'r' };

    const size_t n = s.length();

    unsigned k = n;
    for (size_t i = 0; i < 2; ++i) {
        unsigned b[2] = {};
        for (size_t j = 0, x = i; j < n; ++j) {
            b[x] += (s[j] != t[x]);
            x ^= 1;
        }

        k = std::min(k, std::max(b[0], b[1]));
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin>> s;

    solve(s);

    return 0;
}
