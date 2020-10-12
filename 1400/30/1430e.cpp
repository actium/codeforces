#include <iostream>
#include <string>
#include <vector>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned long long k = 0;

    std::vector<size_t> p[26];
    for (size_t i = 0; i < n; ++i) {
        const size_t d = s[i] - 'a';
        p[d].push_back(i);
    }

    std::vector<unsigned> bit(1 + n);
    for (size_t i = 0; i < n; ++i) {
        const size_t d = s[i] - 'a';

        const size_t x = p[d].back();
        p[d].pop_back();

        for (size_t j = 1 + x; j > 0; j -= (j & -j))
            k += bit[j];

        for (size_t j = 1 + x; j <= n; j += (j & -j))
            ++bit[j];
    }

    answer(k);
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

