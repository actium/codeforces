#include <iostream>

bool check_duplicate_digits(unsigned n)
{
    for (uint16_t used_digits = 0x00; n != 0; n /= 10) {
        const uint16_t digit_mask = 1 << (n % 10);
        if ((used_digits & digit_mask) != 0)
            return true;

        used_digits |= digit_mask;
    }

    return false;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(unsigned l, unsigned r)
{
    for (unsigned x = l; x <= r; ++x) {
        if (!check_duplicate_digits(x))
            return answer(x);
    }

    answer(-1);
}

int main()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}

