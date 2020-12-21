#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned k, unsigned a, unsigned b)
{
    if (a == 0)
        return b % k == 0 ? answer(b / k) : no_answer();

    if (b == 0)
        return a % k == 0 ? answer(a / k) : no_answer();

    const unsigned c = a / k + b / k;

    if (a > k && b > k)
        return answer(c);

    if (a % k == 0 || b % k == 0)
        return answer(c);

    no_answer();
}

int main()
{
    unsigned k, a, b;
    std::cin >> k >> a >> b;

    solve(k, a, b);

    return 0;
}

