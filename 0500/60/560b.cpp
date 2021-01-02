#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a1, unsigned b1, unsigned a2, unsigned b2, unsigned a3, unsigned b3)
{
    if (a1 >= a2 + a3 && b1 >= std::max(b2, b3))
        return answer(true);

    if (a1 >= std::max(b2, b3) && b1 >= a2 + a3)
        return answer(true);

    if (a1 >= a2 + b3 && b1 >= std::max(b2, a3))
        return answer(true);

    if (a1 >= std::max(b2, a3) && b1 >= a2 + b3)
        return answer(true);

    if (a1 >= b2 + a3 && b1 >= std::max(a2, b3))
        return answer(true);

    if (a1 >= std::max(a2, b3) && b1 >= b2 + a3)
        return answer(true);

    if (a1 >= b2 + b3 && b1 >= std::max(a2, a3))
        return answer(true);

    if (a1 >= std::max(a2, a3) && b1 >= b2 + b3)
        return answer(true);

    answer(false);
}

int main()
{
    unsigned a1, b1, a2, b2, a3, b3;
    std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    solve(a1, b1, a2, b2, a3, b3);

    return 0;
}

