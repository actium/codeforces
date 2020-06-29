#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned s)
{
    unsigned x = 0;
    while (s >= 10) {
        const unsigned d = s / 10;
        x += 10 * d;
        s -= 9 * d;
    }

    answer(x + s);
}

void test_case()
{
    unsigned s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


