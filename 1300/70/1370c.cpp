#include <iostream>

bool is_prime(unsigned n)
{
    for (unsigned x = 2; x * x <= n; ++x) {
        if (n % x == 0)
            return false;
    }
    return true;
}

void answer(size_t v)
{
    constexpr const char* s[2] = { "FastestFinger", "Ashishgup" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    if (n == 1)
        return answer(0);

    if (n == 2)
        return answer(1);

    if (n % 2 == 1)
        return answer(1);

    size_t c = 0;
    while (n % 2 == 0) {
        ++c;
        n /= 2;
    }

    if (n == 1)
        return answer(0);

    if (c > 1)
        return answer(1);

    if (is_prime(n))
        return answer(0);

    answer(1);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

