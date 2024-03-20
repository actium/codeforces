#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, unsigned k)
{
    const size_t n = s.length();

    integer t = 0;

    std::vector<unsigned> f(1 + n);
    f[0] = 1;
    for (size_t i = 0, q = 0; i < n; ++i) {
        q += s[i] - '0';
        if (q >= k)
            t += f[q - k];

        ++f[q];
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}
