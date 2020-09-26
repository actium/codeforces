#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, unsigned x, unsigned y)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = n - x; i < n; ++i)
        k += s[i] - '0';

    answer(s[n-1-y] == '1' ? k - 1 : k + 1);
}

int main()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    std::string s;
    std::cin >> s;

    solve(s, x, y);

    return 0;
}

