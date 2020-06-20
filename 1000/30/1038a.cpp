#include <algorithm>
#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    size_t f[26] = {};
    for (const char c : s) {
        if (c >= 'A' && c < 'A' + k)
            ++f[c - 'A'];
    }

    answer(*std::min_element(f + 0, f + k) * k);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

