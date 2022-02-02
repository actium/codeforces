#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> q(1+n);
    for (size_t i = 0; i < n; ++i)
        q[i+1] = q[i] + !!isupper(s[i]);

    unsigned k = n;
    for (size_t i = 0; i <= n; ++i)
        k = std::min<unsigned>(k, i - q[i] + q[n] - q[i]);

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
