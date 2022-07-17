#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& w, unsigned p)
{
    unsigned f[26] = {};
    for (const char c : w)
        ++f[c - 'a'];

    for (unsigned i = 1; i <= 26; ++i) {
        const unsigned k = std::min(f[i-1], p / i);
        f[i-1] = k;
        p -= std::min(p, k * i);
    }

    std::string s;
    for (const char c : w) {
        if (f[c-'a'] == 0)
            continue;

        s.push_back(c);
        --f[c-'a'];
    }

    answer(s);
}

void test_case()
{
    std::string w;
    std::cin >> w;

    unsigned p;
    std::cin >> p;

    solve(w, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
