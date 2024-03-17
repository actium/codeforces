#include <iostream>

bool is_prime(unsigned n)
{
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    if (is_prime(n))
        return answer(1);

    if (n % 2 == 0 || is_prime(n - 2))
        return answer(2);

    answer(3);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
