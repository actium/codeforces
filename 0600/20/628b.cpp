#include <iostream>
#include <string>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned long long k = 0;
    for (size_t i = 0, q = 0; i < n; ++i) {
        const unsigned r = (s[i] - '0') % 4;
        if (r == 0)
            ++k;

        if ((q * 10 + r) % 4 == 0)
            k += i;

        q = r;
    }

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

