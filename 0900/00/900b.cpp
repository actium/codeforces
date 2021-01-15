#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    for (unsigned i = 1; i <= b; ++i) {
        a *= 10;

        const unsigned d = a / b;
        if (d == c)
            return answer(i);

        a -= d * b;
    }

    no_answer();
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

