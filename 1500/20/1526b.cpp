#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x)
{
    for (unsigned d = 0; d < 11 * 111 && x >= d; d += 111) {
        if ((x - d) % 11 == 0)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

