#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, size_t k)
{
    unsigned f[256] = {};
    for (const char c : s)
        ++f[c];

    for (size_t i = 0; i < 256; ++i) {
        f[i] = std::min<unsigned>(f[i], k);
        k -= f[i];
    }

    std::string t;
    for (const char c : s) {
        if (f[c] > 0) {
            --f[c];
        } else {
            t.push_back(c);
        }
    }

    answer(t);
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

