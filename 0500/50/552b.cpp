#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    integer k = 0;

    integer b = 1, c = 0;
    while (b <= n) {
        k += 9 * b * c / 10;
        b *= 10;
        ++c;
    }

    k += (n - b / 10 + 1) * c;

    answer(k);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

