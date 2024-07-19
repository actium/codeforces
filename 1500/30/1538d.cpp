#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

unsigned count(unsigned x)
{
    unsigned k = 0;
    for (unsigned i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            ++k;
            x /= i;
        }
    }
    return k + (x != 1);
}

void solve(unsigned a, unsigned b, unsigned k)
{
    if (count(a) + count(b) < k)
        return answer(false);

    if (k > 1)
        return answer(true);

    answer(a != b && std::max(a, b) % std::min(a, b) == 0);
}

void test_case()
{
    unsigned a, b, k;
    std::cin >> a >> b >> k;

    solve(a, b, k);
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
