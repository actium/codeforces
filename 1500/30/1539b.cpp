#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& f, size_t l, size_t r)
{
    unsigned k = 0;
    for (size_t i = 0; i < 26; ++i)
        k += (f[i][r] - f[i][l-1]) * (i + 1);

    answer(k);
}

int main()
{
    unsigned n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<unsigned>> f(26, std::vector<unsigned>(1 + n));
    for (size_t i = 0; i < 26; ++i) {
        for (size_t j = 0; j < n; ++j)
            f[i][1+j] = f[i][j] + (s[j] == 'a' + i);
    }

    while (q-- > 0) {
        size_t l, r;
        std::cin >> l >> r;

        solve(f, l, r);
    }

    return 0;
}
