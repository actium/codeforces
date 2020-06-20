#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t k, size_t t)
{
    if (t < k)
        return answer(t);

    if (t < n)
        return answer(k);

    answer(n + k - t);
}

int main()
{
    size_t n, k, t;
    std::cin >> n >> k >> t;

    solve(n, k, t);

    return 0;
}

