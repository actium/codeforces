#include <iostream>

bool v[1 + 1000000];

void prepare()
{
    for (unsigned k = 2; k * k < 1000000; ++k) {
        for (unsigned x = k * k, b = 1 + k + x; b <= 1000000; x *= k, b += x)
            v[b] = true;
    }
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    answer(v[n]);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    prepare();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
