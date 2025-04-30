#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool is_prime(unsigned x)
{
    for (unsigned i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return false;
    }
    return x > 1;
}

void solve(unsigned x, unsigned k)
{
    answer(k == 1 ? is_prime(x) : k == 2 && x == 1);
}

void test_case()
{
    unsigned x, k;
    std::cin >> x >> k;

    solve(x, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
