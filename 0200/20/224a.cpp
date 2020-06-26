#include <iostream>

#include <cmath>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned s1, unsigned s2, unsigned s3)
{
    const unsigned a = sqrt(s1 * s3 / s2);
    const unsigned b = sqrt(s1 * s2 / s3);
    const unsigned c = sqrt(s2 * s3 / s1);

    answer(4 * (a + b + c));
}

int main()
{
    unsigned s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    solve(s1, s2, s3);

    return 0;
}

