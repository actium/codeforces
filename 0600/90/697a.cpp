#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned t, unsigned s, unsigned x)
{
    if (x < t + s && x != t)
        return answer(false);

    const unsigned k = x - t;
    answer(k % s < 2);
}

int main()
{
    unsigned t, s, x;
    std::cin >> t >> s >> x;

    solve(t, s, x);

    return 0;
}

