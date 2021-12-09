#include <iostream>

unsigned v[1000];

void initialize()
{
    for (unsigned i = 0, x = 1; i < 1000; ++x) {
        if (x % 3 != 0 && x % 10 != 3)
            v[i++] = x;
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k)
{
    answer(v[k-1]);
}

void test_case()
{
    unsigned k;
    std::cin >> k;

    solve(k);
}

int main()
{
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
