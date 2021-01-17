#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    constexpr char c[3] = { 'B', 'G', 'R' };

    const size_t n = s.length();

    unsigned f[3] = {};
    for (const char x : s) {
        for (size_t i = 0; i < 3; ++i)
            f[i] += (x == c[i]);
    }

    bool v[3] = {};
    for (size_t i = 0; i < 3; ++i) {
        v[i] = v[i] || (f[i] == n) || (f[(i+1)%3] != 0 && f[(i+2)%3] != 0);

        for (size_t j = 0; j < 3; ++j)
            v[j] = v[j] || (j != i && f[i] == 0 && f[j] != 0 && f[3-i-j] > 1);
    }

    std::string t;
    for (size_t i = 0; i < 3; ++i) {
        if (v[i])
            t.push_back(c[i]);
    }

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

