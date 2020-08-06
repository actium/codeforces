#include <iostream>
#include <string>

void answer(char v)
{
    std::cout << v << '\n';
}

void solve(unsigned k)
{
    unsigned b = 1, c = 1;
    while (k >= c * b * 9) {
        k -= c * b * 9;
        b *= 10, ++c;
    }

    if (k % c == 0) {
        const unsigned x = b + k / c - 1;
        answer(std::to_string(x).back());
    } else {
        const unsigned x = b + k / c, r = k % c;
        answer(std::to_string(x)[r-1]);
    }
}

int main()
{
    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}

