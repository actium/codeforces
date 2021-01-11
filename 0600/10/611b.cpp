#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using integer = unsigned long long;

void solve(integer a, integer b)
{
    unsigned k = 0;
    for (unsigned i = 1; i < 63; ++i) {
        for (size_t j = 0; j < i; ++j) {
            const integer x = (2ull << i) - 1 - (1ull << j);
            k += (x >= a && x <= b);
        }
    }

    answer(k);
}

int main()
{
    integer a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

