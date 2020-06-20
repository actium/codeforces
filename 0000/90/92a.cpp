#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t m)
{
    const size_t k = n * (n + 1) / 2;
    m %= k;

    for (size_t i = 1; i <= n; ++i) {
        if (m < i)
            return answer(m);

        m -= i;
    }

    answer(0);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

