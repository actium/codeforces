#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned k, std::string& x)
{
    const size_t n = x.length();

    unsigned s = 0;
    for (const char d : x)
        s += d - '0';

    std::sort(x.begin(), x.end());

    unsigned c = 0;
    for (size_t i = 0; i < n && s < k; s += '9' - x[i++])
        ++c;

    answer(c);
}

int main()
{
    unsigned k;
    std::cin >> k;

    std::string x;
    std::cin >> x;

    solve(k, x);

    return 0;
}

