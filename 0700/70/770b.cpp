#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer x)
{
    std::vector<unsigned> d;
    for (integer n = x; n != 0; n /= 10)
        d.push_back(n % 10);

    unsigned p = 0;
    for (auto i = d.begin(); i != d.end(); ++i) {
        if (*i > 0 && p > 1) {
            for (auto j = d.begin(); j != i; ++j)
                *j = 9;

            --*i;
            p = 0;
        }
        p += 9 - *i;
    }

    integer y = 0, b = 1;
    for (const unsigned q : d) {
        y += b * q;
        b *= 10;
    }

    answer(y);
}

int main()
{
    integer x;
    std::cin >> x;

    solve(x);

    return 0;
}

