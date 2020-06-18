#include <iostream>
#include <string>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> pf(n);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0)
            pf[i] = pf[i-1];

        if (s[i] == 'Q')
            ++pf[i];
    }

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'A')
            count += pf[i] * (pf.back() - pf[i]);
    }

    answer(count);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

