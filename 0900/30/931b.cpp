#include <iostream>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    --a, --b;

    for (unsigned k = 1; n > 2; n /= 2, ++k) {
        a /= 2, b /= 2;
        if (a == b)
            return answer(k);
    }

    answer("Final!");
}

int main()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}

